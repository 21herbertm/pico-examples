/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "/Users/mherbert/pico-sdk/src/rp2_common/hardware_i2c/include/hardware/i2c.h"
#include "pico/stdlib.h"
#include "ltr303.h"

int main() {
    stdio_init_all();
    // Initialize I2C
    i2c_inst_t *i2c = i2c0;
    i2c_init(i2c, 400000);
    gpio_set_function(4, GPIO_FUNC_I2C);
    gpio_set_function(5, GPIO_FUNC_I2C);
    gpio_pull_up(4);
    gpio_pull_up(5);

    ltr303_init(i2c);

    while (true) {
        uint16_t ambient_light = ltr303_read_ambient_light(i2c);
        printf("Hello, world!\n");
        printf("Ambient light: %d\n", ambient_light);
        sleep_ms(1000);
    }
}
