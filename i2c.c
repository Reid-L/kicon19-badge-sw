/*
 * Copyright (c) 2019 Maciej Suminski <orson@orson.net.pl>
 * Copyright (c) 2019 Katarzyna Stachyra <kas.stachyra@gmail.com>
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

#include "i2c.h"
#include "lcd.h"
#include "command_handlers.h"

#include <twi.h>
#include <sysclk.h>
#include <pio.h>

void twi_init(void) {
    twi_options_t opt;
    opt.master_clk = sysclk_get_peripheral_hz();
    opt.speed      = 400000;

    pio_configure(PIOA, PIO_PERIPH_A,
            (PIO_PA3A_TWD0 | PIO_PA4A_TWCK0), PIO_OPENDRAIN | PIO_PULLUP);
    sysclk_enable_peripheral_clock(ID_TWI0);
    pmc_enable_periph_clk(ID_TWI0);

    twi_master_init(TWI0, &opt);
}


void cmd_i2c(const uint8_t* data_in, unsigned int input_len) {
    uint32_t status = TWI_ERROR_TIMEOUT;
    twi_packet_t packet;
    const uint8_t* ptr = &data_in[1];

    packet.chip = *ptr++;
    packet.addr_length = *ptr++;

    if (packet.addr_length > 4) {
        cmd_resp_init(CMD_RESP_INVALID_CMD); return;
    }

    for (uint8_t i = 0; i < packet.addr_length; ++i) {
        packet.addr[i] = *ptr++;
    }

    packet.length = *ptr++;
    packet.buffer = (uint8_t*) ptr; /* discarding const qualifier */

    while(SSD1306_isBusy());    // TODO better synchronization

    switch (data_in[0]) {
        case CMD_I2C_READ:
            status = twi_master_read(TWI0, &packet);
            break;

        case CMD_I2C_WRITE:
            status = twi_master_write(TWI0, &packet);
            break;

        default: cmd_resp_init(CMD_RESP_INVALID_CMD); return;
    }

    if (status == TWI_SUCCESS) {
        cmd_resp_init(CMD_RESP_OK);

        if (data_in[0] == CMD_I2C_READ) {
            cmd_resp_writen(packet.buffer, packet.length);
        }
    } else {
        cmd_resp_init(CMD_RESP_EXEC_ERR);
    }
}
