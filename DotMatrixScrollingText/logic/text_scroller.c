/*
 * text_scroller.c
 *
 * Created: 4/5/2019 5:21:56 PM
 *  Author: Ruben
 */
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

#include "../drivers/dot_matrix.h"

#include "text_scroller.h"
#include "dot_matrix_characters.h"

//char text_buffer[TEXT_MAX_SIZE][DOT_MATRIX_MAX_ROWS]; // text_buffer is a prefilled dictionary so we only have to lookup once. (can't do this. would allocate (256 x 8) bytes)
char *text_buffer;
uint8_t text_length;

uint8_t text_index = 0;
uint8_t char_offset = 0;

uint8_t scroll_speed = 0;
uint8_t scroll_update_counter = 0;

void text_scroller_init(uint8_t initial_speed)
{
    text_scroller_set_scroll_speed(initial_speed);
    dot_matrix_characters_dictionary_init(); // Fill dictionary
    dot_matrix_init();                       // Initialize dot_matrix driver
    dot_matrix_clear();                      // Clear dot_matrix display
}

void text_scroller_set_scroll_speed(uint8_t speed)
{
    scroll_speed = speed;
}

void text_scroller_set_text(char text[TEXT_MAX_SIZE], size_t len)
{
    for (int i = 0; i < len; i++)
    {
        text[i] = toupper(text[i]); // Set characters to uppercase because our dictionary only has support for uppercase characters for now.
    }

    /* Can't do this since we don't have enough memory. (memory overflow)
    for (int i = 0; i < len; i++)
    {
        char c = text[i];
        memcpy(text_buffer[i], dot_matrix_characters_lookup(c), sizeof(text_buffer[i])); // Fill the text_buffer once using memcpy and a dictionary lookup.
    }*/
    text_buffer = text;
    text_length = strlen(text_buffer);
}

void text_scroller_update(void)
{
    if (scroll_update_counter >= scroll_speed)
    {
        scroll_update_counter = 0;
        char *data = dot_matrix_characters_lookup(text_buffer[text_index]);
        dot_matrix_draw_character(data, char_offset);
        char_offset++;
        if (char_offset >= DOT_MATRIX_MAX_COLS)
        {
            char_offset = 0;
        }
    }
    scroll_update_counter++;
}