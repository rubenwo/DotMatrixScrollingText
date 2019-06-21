/*
* main.c
*
* Created: 6/21/2019 12:05:01 PM
*  Author: Ruben
*/

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>
#include <avr/interrupt.h>

#include "led_matrix_driver.h"
#include "led_matrix_scroller.h"

void wait(int ms);

int main( void )
{
	init_led_matrix();
	clear_led_matrix_display();
	
	selectLetters("FUCK DEZE KANKER SHIT");

	while (1)
	{
		scrollLeft();
		
		wait(getScrollingSpeed()*100);
	}

	return 1;
}



void wait(int ms)
{
	for (int i = 0; i < ms; i++)
	{
		_delay_ms(1);
	}
}