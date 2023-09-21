/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "ltr303.h"
#include "OV5640_reg.h" // The header file for the OV5640 camera

#define LIGHT_THRESHOLD 15 // Define a threshold for light intensity

int main() {
    // Initialize stdio
    stdio_init_all();

    // Initialize I2C for the light sensor
    i2c_inst_t *i2c = i2c0;
    i2c_init(i2c, 400000);
    gpio_set_function(4, GPIO_FUNC_I2C);
    gpio_set_function(5, GPIO_FUNC_I2C);
    gpio_pull_up(4);
    gpio_pull_up(5);

    // Initialize LTR-303 light sensor
    ltr303_init(i2c);

    // Initialize OV5640 camera
    OV5640_init(); // Assuming you have a similar function to initialize the camera

    while (1) {
        // Read ambient light from LTR-303
        uint16_t ambient_light = ltr303_read_ambient_light(i2c);

        printf("Ambient light: %d\n", ambient_light);

        // Check if light exceeds threshold
        if (ambient_light > LIGHT_THRESHOLD) {
            // Trigger the camera
            OV5640_start_capture(); // Assuming you have a similar function to start the camera capture
        }

        sleep_ms(1000);
    }

    return 0;
}
