
/*
* main.c
*
* Created: 28-3-2019 13:12:21
*  Author: rickw
*/
#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>
#include <avr/interrupt.h>

#include "dictionary.h"
#include "led_matrix_driver.h"


void wait(int ms);

int main( void )
{
	dotmatrixInit();
	clearDisplay();
	
	selectLetters("FUCK DEZE");

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