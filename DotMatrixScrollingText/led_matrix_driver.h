/*
* led_matrix_driver.h
*
* Created: 6/21/2019 12:05:01 PM
*  Author: Ruben
*/

#ifndef DOTMATRIX_H
#define DOTMATRIX_H

#define DOT_MATRIX_BASE_ADDR 0xE0

//start_led_matrix is a function for starting TWI transmission to the led matrix.
//should be called before writing to the matrix.
void start_led_matrix(void);

//stop_led_matrix is a function for stopping TWI transmission to the led matrix.
//should be called after writing to the matrix.
void stop_led_matrix(void);

//write_led_matrix writes an unsigned char to the TWI connected matrix.
void write_led_matrix(unsigned char data);

//init_led_matrix initializes the led_matrix.
void init_led_matrix(void);

//clear_lead_matrix_display clears the matrix display, turning of all LEDs.
void clear_led_matrix_display(void);

#endif
