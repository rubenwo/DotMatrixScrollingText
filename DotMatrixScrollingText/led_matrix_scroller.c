/*
* led_matrix_scroller.c
*
* Created: 6/21/2019 12:25:54 PM
*  Author: Ruben
*/
#include "led_matrix_scroller.h"
#include "dictionary.h"

int buffer[350];
int updateCount = 0;
int bufferCount = 0;
int scrollingSpeed = SCROLLING_FAST;

void selectLetters(char *word)
{
	for (int i = 0; i < strlen(word); i++)
	{
		character letr = look_up_character(word[i]);
		if(letr.letter != ' ')
		{
			for(int j = 0; j < letr.size; j++)
			{
				buffer[bufferCount] = letr.matrix_structure[j];
				bufferCount++;
			}
			
			buffer[bufferCount] = 0b00000000;
			bufferCount++;
		}
		else
		{
			for(int j = 0; j<4; j++)
			{
				buffer[bufferCount] = 0b00000000;
				bufferCount++;
			}
		}
	}
	
	updateCount = bufferCount + 23;
}

void scrollRight(void)
{
	int i = 0;
	for (int j = 0; j <= 2; j ++)
	{
		start_led_matrix();
		switch (j)
		{
			case 0: write_led_matrix(0xE0); break; // select display
			case 1: write_led_matrix(0xE2); break;
			case 2: write_led_matrix(0xE8); break;
		}
		
		for (int k = 0; k <= 14; k += 2)
		{
			write_led_matrix(k);				   // write the right data of a letter to the right row
			write_led_matrix(buffer[(i - updateCount + bufferCount + 1 >= 0)? i - updateCount + bufferCount + 1 : 299]);
			
			i++;
		}
		
		stop_led_matrix();
	}
	
	updateCount++;
	if (updateCount > bufferCount + 23) // start from the beginning if the whole word is passed
	{
		updateCount = 0;
	}
}

void scrollLeft(void)
{
	int i = 0;
	for (int j = 0; j <= 2; j ++)
	{
		start_led_matrix();
		switch (j)
		{
			case 0: write_led_matrix(0xE0); break; // select display
			case 1: write_led_matrix(0xE2); break;
			case 2: write_led_matrix(0xE8); break;
		}
		
		for (int k = 0; k <= 14; k += 2)
		{
			write_led_matrix(k);				   // write the right data of a letter to the right row
			write_led_matrix(buffer[(i - updateCount + bufferCount + 1 >= 0)? i - updateCount + bufferCount + 1 : 299]);
			
			i++;
		}
		
		stop_led_matrix();
	}
	
	updateCount--;
	if (updateCount <= 0)  // start from the beginning if the whole word is passed
	{
		updateCount = bufferCount + 23;
	}
}

void clearDotmatrixBuffer(void)
{
	for (int i = 0; i < 300; i++)
	buffer[i] = 0;
}

void setScrollingSpeed(int s)
{
	scrollingSpeed = s;
}

int getScrollingSpeed(void)
{
	return scrollingSpeed;
}

