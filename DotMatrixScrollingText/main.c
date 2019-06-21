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

int interrupted = -1;
void wait(int ms);

/*ISR( INT4_vect )
{
if(interrupted == -1){
switch(scroller_get_speed())
{
case SCROLL_MODE_FAST:
scroller_set_speed(SCROLL_MODE_NORMAL);
break;
case SCROLL_MODE_NORMAL:
scroller_set_speed(SCROLL_MODE_SLOW);
break;
case SCROLL_MODE_SLOW:
scroller_set_speed(SCROLL_MODE_FAST);
break;
}
interrupted = 0;
}
}

ISR( INT5_vect )
{
PORTB = 0b00000010;
}

ISR( INT0_vect )
{

}

ISR( INT7_vect )
{
PORTB = 0b00000100;
}*/
int main(void)
{
	// 	DDRF = 0x00;
	// 	DDRB = 0xFF;
	// 	DDRD = 0xFF;
	// 	DDRE = 0x00;
	//
	// 	EICRB |= 0b00000010;
	// 	//EICRA |= 0b00000010;
	// 	EIMSK |= 0b00010001;
	//
	// 	sei();

	init_led_matrix();
	clear_led_matrix_display();

	scroller_set_text("Nerds are the new cool");

	while (1)
	{
		if (interrupted == 0)
		{
			interrupted = -1;
		}
		scroller_scroll_left();

		wait(scroller_get_speed());
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