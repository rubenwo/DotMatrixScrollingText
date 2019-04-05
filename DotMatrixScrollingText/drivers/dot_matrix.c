/*
 * dot_matrix.c
 *
 * Created: 4/5/2019 5:23:30 PM
 *  Author: Ruben
 */

#include "dot_matrix.h"
#include "i2c.h"


void dot_matrix_init(void)
{
    //TODO: Init using i2c
    i2c_init();

}

void dot_matrix_clear(void)
{
}

void dot_matrix_fill(void)
{
}

void dot_matrix_draw_row(int row, int data)
{
}

void dot_matrix_draw_character(char data[DOT_MATRIX_MAX_ROWS])
{
}