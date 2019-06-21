/*
* led_matrix_driver.c.c
*
* Created: 6/21/2019 12:05:01 PM
*  Author: Ruben
*/

#include <avr/io.h>
#include <stdio.h>
#include <string.h>

#include "led_matrix_driver.h"

void start_led_matrix(void)
{
	TWCR = (0x80 | 0x20 | 0x04);
	while( 0x00 == (TWCR & 0x80) );
}

void stop_led_matrix(void)
{
	TWCR = (0x80 | 0x10 | 0x04);
}

void write_led_matrix(unsigned char data)
{
	TWDR = data;
	TWCR = (0x80 | 0x04);
	while (0 == (TWCR & 0x80));
}

void init_led_matrix(void)
{
	TWSR = 0;
	TWBR = 32;
	
	int addr[] = { 0, 2, 8 };
	for (int i = 0; i < 3; i++)
	{
		start_led_matrix();
		write_led_matrix(DOT_MATRIX_BASE_ADDR + addr[i]);
		write_led_matrix(0x21);
		stop_led_matrix();
		
		start_led_matrix();
		write_led_matrix(DOT_MATRIX_BASE_ADDR + addr[i]);
		write_led_matrix(0xA0);
		stop_led_matrix();
		
		start_led_matrix();
		write_led_matrix(DOT_MATRIX_BASE_ADDR + addr[i]);
		write_led_matrix(0xE7);
		stop_led_matrix();
		
		start_led_matrix();
		write_led_matrix(DOT_MATRIX_BASE_ADDR + addr[i]);
		write_led_matrix(0x81);
		stop_led_matrix();
	}
}

void clear_led_matrix_display(void)
{
	int addr[] = { 0, 2, 8 };

	for(int i = 0; i < 3;i++){
		for (int j = 0; j < 8; j++)
		{
			start_led_matrix();
			write_led_matrix(DOT_MATRIX_BASE_ADDR + addr[i]);
			write_led_matrix(0x00 + (j * 2));
			write_led_matrix(0x00);
			stop_led_matrix();
		}
	}
}

