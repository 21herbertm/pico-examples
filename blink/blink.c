/*
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 *
 * */

/*
#include "pico/stdlib.h"


int main() {
#ifndef PICO_DEFAULT_LED_PIN
#warning blink example requires a board with a regular LED
#else
    const uint LED_PIN = 17;//PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) {
        stdio_init_all();
        gpio_put(LED_PIN, 1);
        sleep_ms(250);
        gpio_put(LED_PIN, 0);
        sleep_ms(250);
    }
#endif
}
 */


#include "pico/stdlib.h"
#include "/Users/mherbert/pico-sdk/src/rp2_common/hardware_i2c/include/hardware/i2c.h"
#include "ltr303.h"
#include <stdio.h>
#include "hardware/uart.h"

int main() {
    stdio_init_all();
    sleep_ms(2000); // wait a bit for the serial terminal to open

    // Initialize I2C
    i2c_inst_t *i2c = i2c0;
    i2c_init(i2c, 400000);
    gpio_set_function(4, GPIO_FUNC_I2C);
    gpio_set_function(5, GPIO_FUNC_I2C);
    gpio_pull_up(4);
    gpio_pull_up(5);

    // Initialize LTR303 sensor
    ltr303_init(i2c);

    while (1) {
        // Read ambient light
        uint16_t ambient_light = ltr303_read_ambient_light(i2c);
        printf("Ambient light: \n", ambient_light);

        sleep_ms(1000);
    }

    return 0;
}


 /*


#include "pico/stdlib.h"
#include "/Users/mherbert/pico-sdk/src/rp2_common/hardware_i2c/include/hardware/i2c.h"
#include "ltr303.h"
#include <stdio.h>
#include "hardware/uart.h"


void uart_print(const char *str) {
    for (size_t i = 0; str[i] != '\0'; i++) {
        uart_putc_raw(uart1, str[i]);
    }
}

int main() {
    // Initialize UART
    uart_init(uart1, 115200);
    gpio_set_function(0, GPIO_FUNC_UART);
    gpio_set_function(1, GPIO_FUNC_UART);
    gpio_pull_up(1);

    // Send a string to UART to signify initialization
    uart_print("UART Initialized\n");

    while (1) {
        // Send output to UART
        uart_print("Hello, UART!\n");
        sleep_ms(1000);
    }
}
*/