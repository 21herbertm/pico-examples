#include "ltr303.h"

void ltr303_init(i2c_inst_t *i2c) {
    uint8_t data[2];
    // Set ALS control register for active mode
    data[0] = ALS_CONTR;
    data[1] = 0x01;
    i2c_write_blocking(i2c, LTR303_I2C_ADDR, data, 2, false);

    // Set ALS measurement rate
    data[0] = ALS_MEAS_RATE;
    data[1] = 0x03;  // 50 ms time and 50 ms rate
    i2c_write_blocking(i2c, LTR303_I2C_ADDR, data, 2, false);
}

uint16_t ltr303_read_ambient_light(i2c_inst_t *i2c) {
    uint8_t data[2];
    uint16_t ch0, ch1;

    // Read CH1 data
    data[0] = ALS_DATA_CH1_LOW;
    i2c_write_blocking(i2c, LTR303_I2C_ADDR, data, 1, true);
    i2c_read_blocking(i2c, LTR303_I2C_ADDR, data, 2, false);
    ch1 = (data[1] << 8) | data[0];

    // Read CH0 data
    data[0] = ALS_DATA_CH0_LOW;
    i2c_write_blocking(i2c, LTR303_I2C_ADDR, data, 1, true);
    i2c_read_blocking(i2c, LTR303_I2C_ADDR, data, 2, false);
    ch0 = (data[1] << 8) | data[0];

    // For demonstration, just return CH0
    return ch0;
}
