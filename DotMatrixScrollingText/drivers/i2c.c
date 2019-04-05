/*
 * i2c.c
 *
 * Created: 4/5/2019 5:23:15 PM
 *  Author: Ruben
 */
#include <avr/io.h>
#include <stdint.h>

#include "i2c.h"

void i2c_init(void)
{
    TWSR = 0x00;
    TWBR = 0x20;
}

void i2c_start(void)
{
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    i2c_wait();
}

void i2c_wait(void)
{
    while (!(TWCR & (1 << TWINT)))
        ;
}

void i2c_stop(void)
{
    TWCR = ((1 << TWINT) | (1 << TWEN) | (1 << TWSTO));
}

void i2c_select(uint8_t address, I2C_MODE mode)
{
    TWDR = (address & 0xFE) | (mode);
    TWCR = (1 << TWINT) | (1 << TWEN);
    i2c_wait();
}

void i2c_write(uint8_t data)
{
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    i2c_wait();
}

uint8_t i2c_read(void)
{
    //TODO: implement i2c_read when necessary.
    return 0;
}