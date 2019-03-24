#include <stdint.h>

const uint8_t kicon_logo[128*32/8] = {
    0xff,0xff,0xff,0xff,0xfc,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
    ,0xff,0xff,0xff,0xff,0xf8,0x0f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
    ,0xff,0x80,0x1f,0x80,0x10,0x07,0xff,0xc0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff
    ,0xff,0x80,0x1f,0x80,0x10,0x07,0xff,0x00,0x07,0xff,0xff,0xff,0xff,0xff,0xff,0xff
    ,0xff,0xc0,0x3f,0x00,0x30,0x07,0xfc,0x00,0x01,0xff,0xff,0xff,0xff,0xff,0xff,0xff
    ,0xff,0xc0,0x3f,0x00,0x70,0x07,0xf8,0x00,0x01,0xff,0xff,0xff,0xff,0xff,0xff,0xff
    ,0xff,0xc0,0x3e,0x00,0xf0,0x07,0xf0,0x00,0x03,0xff,0xff,0xff,0xff,0xff,0xff,0xff
    ,0xff,0xc0,0x3c,0x01,0xf8,0x0f,0xe0,0x00,0x03,0xff,0xff,0xff,0xff,0xff,0xff,0xff
    ,0xff,0xc0,0x38,0x03,0xfe,0x3f,0xe0,0x02,0x07,0xff,0xff,0xff,0xff,0xff,0xff,0xff
    ,0xff,0xc0,0x30,0x03,0xff,0xff,0xc0,0x0f,0xcf,0xff,0xff,0xff,0xff,0xff,0xff,0xff
    ,0xff,0xc0,0x30,0x07,0xe0,0x07,0xc0,0x1f,0xef,0xfe,0x00,0xff,0x80,0x60,0x1f,0xff
    ,0xff,0xc0,0x20,0x0f,0xf0,0x0f,0x80,0x3f,0xff,0xf8,0x00,0x3f,0x80,0x00,0x0f,0xff
    ,0xff,0xc0,0x00,0x1f,0xf0,0x0f,0x80,0x3f,0xff,0xe0,0x00,0x1f,0x80,0x00,0x07,0xff
    ,0xff,0xc0,0x00,0x3f,0xf0,0x0f,0x80,0x7f,0xff,0xe0,0x00,0x0f,0xc0,0x00,0x03,0xff
    ,0xff,0xc0,0x00,0x3f,0xf0,0x0f,0x80,0x7f,0xff,0xc0,0x00,0x07,0xc0,0x00,0x03,0xff
    ,0xff,0xc0,0x00,0x7f,0xf0,0x0f,0x80,0x7f,0xff,0x80,0x00,0x07,0xc0,0x00,0x03,0xff
    ,0xff,0xc0,0x00,0xff,0xf0,0x0f,0x00,0x7f,0xff,0x80,0x38,0x07,0xc0,0x18,0x03,0xff
    ,0xff,0xc0,0x00,0x7f,0xf0,0x0f,0x00,0x7f,0xff,0x80,0x7c,0x03,0xc0,0x7c,0x03,0xff
    ,0xff,0xc0,0x00,0x7f,0xf0,0x0f,0x00,0x7f,0xff,0x00,0xfe,0x03,0xc0,0x7e,0x03,0xff
    ,0xff,0xc0,0x00,0x3f,0xf0,0x0f,0x00,0x7f,0xff,0x00,0xfe,0x03,0xc0,0x7e,0x03,0xff
    ,0xff,0xc0,0x00,0x1f,0xf0,0x0f,0x80,0x7f,0xff,0x00,0xfe,0x03,0xc0,0x7e,0x03,0xff
    ,0xff,0xc0,0x00,0x1f,0xf0,0x0f,0x80,0x7f,0xff,0x00,0xfe,0x03,0xc0,0x7e,0x03,0xff
    ,0xff,0xc0,0x20,0x0f,0xf0,0x0f,0x80,0x3f,0xff,0x00,0xfe,0x03,0xc0,0x7e,0x03,0xff
    ,0xff,0xc0,0x20,0x07,0xf0,0x0f,0x80,0x3f,0xff,0x00,0xfe,0x03,0xc0,0x7e,0x03,0xff
    ,0xff,0xc0,0x30,0x03,0xf0,0x0f,0xc0,0x1f,0xe7,0x00,0xfe,0x03,0xc0,0x7e,0x03,0xff
    ,0xff,0xc0,0x38,0x03,0xf0,0x0f,0xc0,0x0f,0xc7,0x80,0x7c,0x03,0xc0,0x7e,0x03,0xff
    ,0xff,0xc0,0x3c,0x01,0xf0,0x0f,0xe0,0x00,0x03,0x80,0x38,0x07,0xc0,0x7e,0x03,0xff
    ,0xff,0xc0,0x3c,0x00,0xf0,0x0f,0xe0,0x00,0x03,0xc0,0x00,0x07,0xc0,0x7e,0x03,0xff
    ,0xff,0xc0,0x3e,0x00,0x70,0x0f,0xf0,0x00,0x01,0xc0,0x00,0x0f,0xc0,0x7e,0x03,0xff
    ,0xff,0xc0,0x3f,0x00,0x70,0x0f,0xf8,0x00,0x01,0xe0,0x00,0x0f,0xc0,0x7e,0x03,0xff
    ,0xff,0xc0,0x1f,0x00,0x30,0x0f,0xfc,0x00,0x01,0xf0,0x00,0x3f,0x80,0x3c,0x03,0xff
    ,0xff,0x80,0x1f,0x00,0x20,0x07,0xff,0x00,0x07,0xf8,0x00,0x7f,0x80,0x38,0x01,0xff
};


const uint8_t gfx_test[96*64/8]={
    0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xff,0xff,0xff
    ,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0xff,0xff,0xff
    ,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf3,0xf8,0xff,0xff,0xff
    ,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe1,0xf0,0xff,0xff,0xff
    ,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0xf0,0xe3,0xff,0xf8
    ,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0xcc,0x06,0xc3,0xff,0xe0
    ,0xff,0xdf,0xff,0xff,0xff,0xff,0xe0,0x0f,0x06,0x1b,0xff,0x81
    ,0xfc,0x00,0xff,0xff,0xff,0xff,0x87,0x0f,0xff,0x98,0xfe,0x43
    ,0xf8,0xfc,0x7f,0xff,0xff,0xff,0x83,0xef,0xff,0x82,0x7c,0x4f
    ,0xf3,0xff,0x3f,0xff,0xff,0xff,0xf1,0x9f,0xff,0x87,0x02,0x9f
    ,0xe7,0xff,0xdf,0xff,0xff,0xff,0xc1,0x7f,0xdf,0xb2,0x02,0x3f
    ,0xef,0xff,0xcf,0xff,0xff,0xff,0x8f,0xff,0xdf,0x7a,0x52,0x7f
    ,0xef,0xff,0xe7,0xf8,0x3f,0xff,0x3f,0xff,0xbe,0x7c,0x51,0xff
    ,0xef,0xe7,0xb7,0xc0,0x01,0xff,0x3f,0xfd,0xb6,0x7c,0x53,0xff
    ,0xee,0xdf,0xd3,0x0f,0xf8,0x3f,0x3f,0xba,0x66,0xfe,0x00,0x3f
    ,0xee,0xd8,0x68,0x3f,0xff,0x1f,0x03,0x75,0xc2,0x72,0x70,0x3f
    ,0xe6,0xb0,0x04,0x7f,0xff,0xc6,0x02,0xff,0x86,0xf1,0xf0,0xff
    ,0xe7,0xa7,0x0c,0xff,0xff,0xe0,0x4f,0xff,0x30,0xe0,0xe3,0xff
    ,0xf3,0xe7,0x99,0xff,0xff,0xff,0xd9,0xe6,0x71,0xf1,0xe3,0xff
    ,0xf3,0xef,0xc1,0xff,0xff,0xff,0x99,0xe4,0xfe,0xf9,0xef,0xff
    ,0xf9,0xe7,0xf3,0xff,0xff,0xff,0x9f,0xc4,0xfe,0x7f,0xcf,0xff
    ,0xfd,0xa7,0xf3,0xff,0xff,0xff,0x9f,0xc4,0xfe,0x7f,0xdf,0xff
    ,0xfd,0xa7,0xf7,0xff,0xff,0xff,0x90,0xd4,0xfc,0x7f,0xcf,0xff
    ,0x7d,0xf7,0xe7,0xff,0xff,0xff,0x81,0x90,0xfd,0x3f,0xcf,0xff
    ,0x3c,0xf7,0xe7,0xff,0xff,0xff,0xc1,0x38,0xfd,0x9f,0xcf,0xff
    ,0x1d,0xe7,0xe7,0xff,0xff,0xff,0xc2,0x3f,0xfd,0x9f,0xcf,0xff
    ,0x01,0xe7,0xe7,0xff,0xff,0xff,0xf0,0x7f,0xfd,0xc7,0xcf,0xff
    ,0x1f,0xcf,0xe7,0xff,0xff,0xff,0xe0,0xff,0xfc,0xc6,0xcf,0xff
    ,0x3f,0x9f,0xe7,0xff,0xff,0xff,0xe1,0xff,0xfc,0xe6,0xdf,0xff
    ,0x8c,0x3f,0xe7,0xff,0xff,0xff,0xe3,0xff,0xfc,0xe7,0x9f,0xff
    ,0xe0,0xff,0xc7,0xff,0xfb,0xff,0xe3,0xff,0xfc,0xf8,0x3f,0xff
    ,0xff,0xe0,0x0f,0xff,0xf3,0xff,0xff,0xff,0xfc,0xfc,0xff,0xff
    ,0xff,0xe7,0xff,0xff,0xf7,0xff,0xff,0xff,0xfd,0xff,0xff,0xff
    ,0xff,0xcf,0xff,0xff,0xf7,0xff,0xff,0xff,0xf9,0xff,0xff,0xff
    ,0xff,0xcf,0xff,0xff,0xf7,0xff,0xff,0xff,0xf9,0xff,0xff,0xff
    ,0xff,0xcf,0xff,0xff,0xe7,0xff,0xff,0x3f,0xfc,0xff,0xff,0xff
    ,0xff,0xcf,0xff,0xff,0xe3,0xff,0xff,0x9f,0xf6,0x7f,0xff,0xff
    ,0xff,0xef,0xff,0xff,0x80,0xff,0xff,0x9f,0xf3,0x3f,0xff,0xff
    ,0xff,0xe7,0xff,0xff,0x1e,0x3f,0xff,0xcf,0xf3,0x9f,0xff,0xff
    ,0xff,0xe7,0xe7,0xfc,0x7f,0x80,0x3f,0x87,0xfb,0x9f,0xff,0xff
    ,0xff,0xf7,0xc0,0x01,0xff,0xe0,0x00,0x03,0xf9,0xcf,0xff,0xff
    ,0xff,0xf3,0xce,0x07,0xff,0xff,0xff,0xf8,0x7c,0xe7,0xff,0xff
    ,0xff,0xf3,0xcf,0xbf,0xff,0xff,0xff,0xfc,0x0e,0x77,0xff,0xff
    ,0xff,0xf9,0xcf,0x9f,0xff,0xff,0xff,0xff,0x87,0x13,0xff,0xff
    ,0xff,0xf9,0xef,0xdf,0xff,0xff,0xff,0xff,0xf3,0x99,0xff,0xff
    ,0xff,0xf9,0xe7,0xcf,0xff,0xff,0xff,0xff,0xf3,0xc9,0xff,0xff
    ,0xff,0xfd,0xe7,0xcf,0xff,0xff,0xff,0xff,0xf3,0xc9,0xff,0xff
    ,0xff,0xfc,0xf7,0xe7,0xff,0xff,0xff,0xff,0xf3,0xc9,0xff,0xff
    ,0xff,0xfc,0xf3,0xe7,0xff,0xff,0xff,0xff,0xf7,0xc3,0xff,0xff
    ,0xff,0xfc,0xf3,0xf7,0xff,0xff,0xff,0xff,0xe7,0x07,0xff,0xff
    ,0xff,0xfc,0xf9,0xf3,0xff,0xff,0xff,0xff,0xc6,0x07,0xff,0xff
    ,0xff,0xfc,0xf9,0xfb,0xff,0xff,0xff,0xff,0x8c,0xcf,0xff,0xff
    ,0xff,0xfc,0xfc,0xf3,0xff,0xff,0xff,0xe0,0x3c,0xcf,0xff,0xff
    ,0xff,0xfe,0x7c,0xf3,0xff,0xff,0xff,0xe0,0x79,0x9f,0xff,0xff
    ,0xff,0xfe,0x79,0xe7,0xff,0xff,0xff,0xcb,0xf9,0x1f,0xff,0xff
    ,0xff,0xfe,0x79,0xe7,0xff,0xff,0xff,0xcb,0xf2,0x3f,0xff,0xff
    ,0xff,0xfc,0x79,0x27,0xff,0xff,0xff,0x92,0x60,0x7f,0xff,0xff
    ,0xff,0xfc,0x38,0xc7,0xff,0xff,0xff,0x80,0x00,0xff,0xff,0xff
    ,0xff,0xfc,0xc1,0xe7,0xff,0xff,0xff,0x83,0xff,0xff,0xff,0xff
    ,0xff,0xfc,0xf0,0x67,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
    ,0xff,0xfe,0x72,0x27,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
    ,0xff,0xff,0x17,0x07,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
    ,0xff,0xff,0x87,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
    ,0xff,0xff,0xef,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
};