/*
* led_matrix_driver.h
*
* Created: 6/21/2019 12:05:01 PM
*  Author: Ruben
*/

#ifndef DOTMATRIX_H
#define DOTMATRIX_H

#define DOT_MATRIX_BASE_ADDR 0xE0

void start_led_matrix(void);
void stop_led_matrix(void);
void write_led_matrix(unsigned char data);
void init_led_matrix(void);

void clear_led_matrix_display(void);

#endif
