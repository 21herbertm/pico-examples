//
// Created by Melanie Herbert on 9/20/23.
//

#ifndef PICO_EXAMPLES_LTR303_H
#define PICO_EXAMPLES_LTR303_H

#endif //PICO_EXAMPLES_LTR303_H

#ifndef LTR_303_H
#define LTR_303_H

#include "pico/stdlib.h"
#include "/Users/mherbert/pico-sdk/src/rp2_common/hardware_i2c/include/hardware/i2c.h"

#define LTR303_I2C_ADDR 0x29

// Register addresses
#define ALS_CONTR 0x80
#define ALS_MEAS_RATE 0x85
#define ALS_DATA_CH1_LOW 0x88
#define ALS_DATA_CH1_HIGH 0x89
#define ALS_DATA_CH0_LOW 0x8A
#define ALS_DATA_CH0_HIGH 0x8B

// Functions
void ltr303_init(i2c_inst_t *i2c);
uint16_t ltr303_read_ambient_light(i2c_inst_t *i2c);

#endif // LTR_303_H

