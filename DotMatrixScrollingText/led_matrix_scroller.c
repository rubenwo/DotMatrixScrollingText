/*
* led_matrix_scroller.c
*
* Created: 6/21/2019 12:25:54 PM
*  Author: Ruben
*/
#include <string.h>
#include <ctype.h>

#include "led_matrix_scroller.h"
#include "led_matrix_driver.h"
#include "dictionary.h"

int buffer[SCROLL_BUFFER_SIZE];
int updateCount = 0;
int bufferCount = 0;
int scrollingSpeed = SCROLL_MODE_FAST; // default SCROLL_MODE

void scroller_set_text(char *word)
{
	for (int i = 0; i < strlen(word); i++)
	{
		word[i] = toupper(word[i]); // change char to uppercase as look_up_character is case sensitive and doesn't have lowercase entries.
		character c = look_up_character(word[i]);
		// Add a character.
		for (int j = 0; j < c.size; j++)
		{
			buffer[bufferCount] = c.matrix_structure[j]; // set the buffer at position bufferCount to the character structure from the dictionary.
			bufferCount++;
		}

		buffer[bufferCount] = 0b00000000; // writing empty column after letter for readability.
		bufferCount++;
	}

	updateCount = bufferCount + 23; // white space after sentence.
}

void scroller_scroll_right(void)
{
	int i = 0;
	start_led_matrix();
	write_led_matrix(DOT_MATRIX_BASE_ADDR); // Display I2C addres + R/W bit

	for (int j = 0; j <= 14; j += 2)
	{
		write_led_matrix(j);																											 // Address
		write_led_matrix(buffer[(i - updateCount + bufferCount + 1 >= 0) ? i - updateCount + bufferCount + 1 : SCROLL_BUFFER_SIZE - 1]); // data
		i++;
	}

	stop_led_matrix();

	updateCount++;
	if (updateCount > bufferCount + 23)
	{
		updateCount = 0;
	}
}

void scroller_scroll_left(void)
{
	int i = 0;

	start_led_matrix();
	write_led_matrix(DOT_MATRIX_BASE_ADDR); // Display I2C addres + R/W bit

	for (int j = 0; j <= 14; j += 2)
	{
		write_led_matrix(j);																											 // Address
		write_led_matrix(buffer[(i - updateCount + bufferCount + 1 >= 0) ? i - updateCount + bufferCount + 1 : SCROLL_BUFFER_SIZE - 1]); // data
		i++;
	}

	stop_led_matrix();

	updateCount--;
	if (updateCount <= 0)
	{
		updateCount = bufferCount + 23;
	}
}

void scroller_clear_buffer(void)
{
	for (int i = 0; i < SCROLL_BUFFER_SIZE; i++)
	{
		buffer[i] = 0;
	}
}

void scroller_set_speed(int speed)
{
	scrollingSpeed = speed;
}

int scroller_get_speed(void)
{
	return scrollingSpeed;
}
