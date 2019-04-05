/*
 * dot_matrix.c
 *
 * Created: 4/5/2019 5:23:30 PM
 *  Author: Ruben
 */
#include <stdint.h>

#include "dot_matrix.h"
#include "i2c.h"

#define MATRIX_ADDR 0xE0
#define MATRIX_ON 0x21
#define MATRIX_OUTPUT 0xA0

void dot_matrix_init(void)
{
    i2c_start();
    i2c_select(MATRIX_ADDR, I2C_MODE_W);
    i2c_write(MATRIX_ON);
    i2c_stop();

    i2c_start();
    i2c_select(MATRIX_ADDR, I2C_MODE_W);
    i2c_write(MATRIX_OUTPUT);
    i2c_stop();
}

void dot_matrix_clear(void)
{
    for (int i = 0; i < DOT_MATRIX_MAX_ROWS; i++)
    {
        dot_matrix_draw_row(i, 0x00);
    }
}

void dot_matrix_fill(void)
{
}

void dot_matrix_draw_row(int row, int data)
{
}

void dot_matrix_draw_character(char data[DOT_MATRIX_MAX_ROWS], uint8_t offset)
{
    for (int i = 0; i < DOT_MATRIX_MAX_ROWS; i++)
    {
        dot_matrix_draw_row(DOT_MATRIX_MAX_ROWS - 1 - i, data[i]);
    }
}