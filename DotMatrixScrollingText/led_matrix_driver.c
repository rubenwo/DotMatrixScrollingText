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

/******************************************************************/
void start_led_matrix(void)
/* 
short:			Generate TWI start condition
inputs:		
outputs:	
notes:			
Version :    	DMK, Initial code
*******************************************************************/
{
	TWCR = (0x80 | 0x20 | 0x04);
	while (0x00 == (TWCR & 0x80))
		;
}
/******************************************************************/
void stop_led_matrix(void)
/* 
short:			Generate TWI stop condition
inputs:		
outputs:	
notes:			
Version :    	DMK, Initial code
*******************************************************************/
{
	TWCR = (0x80 | 0x10 | 0x04);
}
/******************************************************************/
void write_led_matrix(unsigned char data)
/* 
short:			transmit 8 bits data
inputs:		
outputs:	
notes:			
Version :    	DMK, Initial code
*******************************************************************/
{
	TWDR = data;
	TWCR = (0x80 | 0x04);
	while (0 == (TWCR & 0x80))
		;
}

void init_led_matrix(void)
{
	TWSR = 0;
	TWBR = 32; // TWI clock set to 100kHz, prescaler = 0

	start_led_matrix();
	write_led_matrix(DOT_MATRIX_BASE_ADDR); //Display I2C addres + R/W bit
	write_led_matrix(0x21);					//Internal osc on (page 10 HT16K33)
	stop_led_matrix();

	start_led_matrix();
	write_led_matrix(DOT_MATRIX_BASE_ADDR); //Display I2C addres + R/W bit
	write_led_matrix(0xA0);					//HT16K33 pins all output
	stop_led_matrix();

	start_led_matrix();
	write_led_matrix(DOT_MATRIX_BASE_ADDR); //Display I2C addres + R/W bit
	write_led_matrix(0xE7);					//Display Dimming 4/16 duty cycle
	stop_led_matrix();

	start_led_matrix();
	write_led_matrix(DOT_MATRIX_BASE_ADDR); //Display I2C addres + R/W bit
	write_led_matrix(0x81);					//Display OFF - Blink On
	stop_led_matrix();
}

void clear_led_matrix_display(void)
{

	for (int i = 0; i < 8; i++)
	{
		start_led_matrix();
		write_led_matrix(DOT_MATRIX_BASE_ADDR);
		write_led_matrix(0x00 + (i * 2));
		write_led_matrix(0x00);
		stop_led_matrix();
	}
}
