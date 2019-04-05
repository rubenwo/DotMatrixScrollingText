/*
 * i2c.h
 *
 * Created: 4/5/2019 5:23:52 PM
 *  Author: Ruben
 */

#ifndef I2C_H_
#define I2C_H_
#include <stdint.h>

typedef enum
{
    I2C_MODE_W = 0,
    I2C_MODE_R = 1
} I2C_MODE;

void i2c_init(void);

void i2c_start(void);

void i2c_wait(void);

void i2c_stop(void);

void i2c_select(uint8_t addr, I2C_MODE mode);

void i2c_write(uint8_t data);

uint8_t i2c_read(void);

#endif /* I2C_H_ */