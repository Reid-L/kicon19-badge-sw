/*
 * Copyright (c) 2019 Maciej Suminski <orson@orson.net.pl>
 *
 * This source code is free software; you can redistribute it
 * and/or modify it in source code form under the terms of the GNU
 * General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include "asf.h"
#include "buttons.h"
#include "io_capture.h"
#include "logic_analyzer.h"
#include "udc.h"
#include "udi_cdc.h"
#include "commands.h"
#include "spi_master.h"
#include "lcd.h"
#include "gfx.h"
#include "SSD1306_commands.h"
#include "scope.h"
#include "serial.h"
#include "menu.h"
#include "led.h"
#include "buffer.h"
#include <string.h>
#include <stdlib.h>

/* Global large buffer */
buffer_t buffer;

volatile bool g_interrupt_enabled = true;

#define SCREENSIZE  140

#define HACK  "Hackaday            "    
#define LINE0 " __  __ _ _         "
#define LINE1 "|  \\/  (_) | _____  "
#define LINE2 "| |\\/| | | |/ / _ \\ "
#define LINE3 "| |  | | |   <  __/ "
#define LINE4 "|_|  |_|_|_|\\_\\___| "

#define RANDCLEARCHAR '*'

/**
 *  \brief Handler for System Tick interrupt.
 *
 *  Process System Tick Event
 */
void SysTick_Handler(void)
{
}


/**
 * \brief initialize pins, watchdog, etc.
 */
static void init_system(void)
{
    /* Disable the watchdog */
    wdt_disable(WDT);

    irq_initialize_vectors();
    cpu_irq_enable();

    /* Initialize the system clock */
    sysclk_init();

    /* Configure timer ISR to fire regularly (100 ms) */
    /* SysTick_Config((sysclk_get_cpu_hz() / 1000) * 100); */

    serial_init(115200);
    led_init();
    btn_init();
    spi_init(1000000, 0);
    SSD1306_init();
    ioc_init();
    la_init();
    udc_start();

    //led_blink(LED2, 4);
}

void delay(int magnitude) {
  for(int i = 0; i < (1 << magnitude); ++i) {
    if (btn_state()) {
      break;
    }
  }
}

void rando(void) {
  char l0[20] = HACK;
  char l1[20] = "                    ";
  char l2[20] = LINE0;
  char l3[20] = LINE1;
  char l4[20] = LINE2;
  char l5[20] = LINE3;
  char l6[20] = LINE4;
  
  char *lines[7] = { l0, l1, l2, l3, l4, l5, l6 };
   
  while(SSD1306_isBusy());
  SSD1306_clearBufferFull();
  SSD1306_drawBufferDMA();

  int counter = 0;

  while (counter < SCREENSIZE) {
    while(SSD1306_isBusy());

    while(1) {
      int myrand = rand()%SCREENSIZE;
      if (lines[myrand/20][myrand%20] != RANDCLEARCHAR) {
        lines[myrand/20][myrand%20] = RANDCLEARCHAR;
        break;
      }
    }

    int row = counter/20;
    int col = counter%20;
    
    /*
    switch(row) {
      case 0:
        l0[col] = '0';
        break;
      case 1:
        l1[col] = '0';
        break;
      case 2:
        l2[col] = '0';
        break;
      case 3:
        l3[col] = '0';
        break;
      case 4:
        l4[col] = '0';
        break;
      case 5:
        l5[col] = '0';
        break;
      case 6:
        l6[col] = '0';           
        break;
    }
    */

    SSD1306_setString(0, 0, l0, 20, WHITE);
    SSD1306_setString(0, 1, l1, 20, WHITE);
    SSD1306_setString(0, 2, l2, 20, WHITE);
    SSD1306_setString(0, 3, l3, 20, WHITE);
    SSD1306_setString(0, 4, l4, 20, WHITE);
    SSD1306_setString(0, 5, l5, 20, WHITE);
    SSD1306_setString(0, 6, l6, 20, WHITE);
    SSD1306_drawBufferDMA();
    ++counter;
    delay(16);
  }
  counter = 0;
  while (counter < 20) {
    for (int j=0; j<7; j++) {
      lines[j][counter] = ' ';
    }
    SSD1306_setString(0, 0, l0, 20, WHITE);
    SSD1306_setString(0, 1, l1, 20, WHITE);
    SSD1306_setString(0, 2, l2, 20, WHITE);
    SSD1306_setString(0, 3, l3, 20, WHITE);
    SSD1306_setString(0, 4, l4, 20, WHITE);
    SSD1306_setString(0, 5, l5, 20, WHITE);
    SSD1306_setString(0, 6, l6, 20, WHITE);
    SSD1306_drawBufferDMA();
    ++counter;
    delay(16);
  }
}


int main(void)
{
    init_system();

    led_set(LED1,1);
    led_set(LED2,1);

    int cur = 0;
    int count = 0;
    int dir = 1;

    while(1) {
      /* Splash screen */
      SSD1306_drawBitmap(0, 0, hack_logo, 128, 64);
      //SSD1306_setPixel(127, 0, WHITE);
      SSD1306_drawBufferDMA();


      /* wait ~3s or till a button is pressed */
      delay(20);
      delay(20);
  
      int loopcount = 0;
      SSD1306_clearBufferFull();
      SSD1306_setString(0, 0, HACK, strlen(HACK),WHITE);
      SSD1306_setString(0, 2, LINE0, strlen(LINE0),WHITE);
      SSD1306_setString(0, 3, LINE1, strlen(LINE1),WHITE);
      SSD1306_setString(0, 4, LINE2, strlen(LINE2),WHITE);
      SSD1306_setString(0, 5, LINE3, strlen(LINE3),WHITE);
      SSD1306_setString(0, 6, LINE4, strlen(LINE4),WHITE);

      //SSD1306_setPixel(127, 0, WHITE);
      SSD1306_drawBufferDMA();
      while(1) {
        while(SSD1306_isBusy());
        SSD1306_setString(cur,1," ",1,WHITE);
        if (dir) {
          if (++cur == 119) {
            dir = 0;          
          }
        }
        else {
          if (--cur == 0 ) {
            dir = 1;          
          }
        }
        SSD1306_setString(cur,1,"_",1,WHITE);
        SSD1306_drawBufferDMA();
        // wait ~3s or till a button is pressed 
        while(count < (1<<10)) {
          count += 1;
        }
      if (loopcount++ > 500) break;
      }
      rando();
    }
}
