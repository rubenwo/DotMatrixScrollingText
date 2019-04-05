/*
 * dot_matrix_characters.c
 *
 * Created: 4/5/2019 5:24:27 PM
 *  Author: Ruben
 */
#include "dot_matrix_characters.h"

M_Character dictionary[DICTIONARY_LEN];

void dot_matrix_characters_dictionary_init(void)
{
    dictionary[0] =  (M_Character){'A', {
	    0b00000000,
	    0b00111100,
	    0b01100110,
	    0b01100110,
	    0b01111110,
	    0b01100110,
	    0b01100110,
	    0b01100110
    }};
    
    dictionary[1] = (M_Character) {'B', {
	    0b00000000,
	    0b01111100,
	    0b01100110,
	    0b01100110,
	    0b01111100,
	    0b01100110,
	    0b01100110,
	    0b01111100
    }};
    
    dictionary[2] = (M_Character) {'C', {
	    0b00000000,
	    0b00111100,
	    0b01100110,
	    0b01100000,
	    0b01100000,
	    0b01100000,
	    0b01100110,
	    0b00111100
    }};
    
    dictionary[3] = (M_Character) {'D', {
	    0b00000000,
	    0b01111100,
	    0b01100110,
	    0b01100110,
	    0b01100110,
	    0b01100110,
	    0b01100110,
	    0b01111100
    }};
    
    dictionary[4] = (M_Character) {'E', {
	    0b00000000,
	    0b01111110,
	    0b01100000,
	    0b01100000,
	    0b01111100,
	    0b01100000,
	    0b01100000,
	    0b01111110
    }};
    
    dictionary[5] = (M_Character) {'F', {
	    0b00000000,
	    0b01111110,
	    0b01100000,
	    0b01100000,
	    0b01111100,
	    0b01100000,
	    0b01100000,
	    0b01100000
    }};
    
    dictionary[6] = (M_Character) {'G', {
	    0b00000000,
	    0b00111100,
	    0b01100110,
	    0b01100000,
	    0b01100000,
	    0b01101110,
	    0b01100110,
	    0b00111100
    }};
    
    dictionary[7] = (M_Character) {'H', {
	    0b00000000,
	    0b01100110,
	    0b01100110,
	    0b01100110,
	    0b01111110,
	    0b01100110,
	    0b01100110,
	    0b01100110
    }};
    
    dictionary[8] = (M_Character) {'I', {
	    0b00000000,
	    0b00111100,
	    0b00011000,
	    0b00011000,
	    0b00011000,
	    0b00011000,
	    0b00011000,
	    0b00111100
    }};
    
    dictionary[9] = (M_Character) {'J', {
	    0b00000000,
	    0b00011110,
	    0b00001100,
	    0b00001100,
	    0b00001100,
	    0b01101100,
	    0b01101100,
	    0b00111000
    }};
    
    dictionary[10] = (M_Character) {'K', {
	    0b00000000,
	    0b01100110,
	    0b01101100,
	    0b01111000,
	    0b01110000,
	    0b01111000,
	    0b01101100,
	    0b01100110
    }};
    
    dictionary[11] = (M_Character) {'L', {
	    0b00000000,
	    0b01100000,
	    0b01100000,
	    0b01100000,
	    0b01100000,
	    0b01100000,
	    0b01100000,
	    0b01111110
    }};
    
    dictionary[12] = (M_Character) {'M', {
	    0b00000000,
	    0b01100011,
	    0b01110111,
	    0b01111111,
	    0b01101011,
	    0b01100011,
	    0b01100011,
	    0b01100011
    }};
    
    dictionary[13] = (M_Character) {'N', {
	    0b00000000,
	    0b01100011,
	    0b01110011,
	    0b01111011,
	    0b01101111,
	    0b01100111,
	    0b01100011,
	    0b01100011
    }};
    
    dictionary[14] = (M_Character) {'O', {
	    0b00000000,
	    0b00111100,
	    0b01100110,
	    0b01100110,
	    0b01100110,
	    0b01100110,
	    0b01100110,
	    0b00111100
    }};
    
    dictionary[15] = (M_Character) {'P', {
	    0b00000000,
	    0b01111100,
	    0b01100110,
	    0b01100110,
	    0b01100110,
	    0b01111100,
	    0b01100000,
	    0b01100000
    }};
    
    dictionary[16] = (M_Character) {'Q', {
	    0b00000000,
	    0b00111100,
	    0b01100110,
	    0b01100110,
	    0b01100110,
	    0b01101110,
	    0b00111100,
	    0b00000110
    }};
    
    dictionary[17] = (M_Character) {'R', {
	    0b00000000,
	    0b01111100,
	    0b01100110,
	    0b01100110,
	    0b01111100,
	    0b01111000,
	    0b01101100,
	    0b01100110
    }};
    
    dictionary[18] = (M_Character) {'S', {
	    0b00000000,
	    0b00111100,
	    0b01100110,
	    0b01100000,
	    0b00111100,
	    0b00000110,
	    0b01100110,
	    0b00111100
    }};
    
    dictionary[19] = (M_Character) {'T', {
	    0b00000000,
	    0b01111110,
	    0b01011010,
	    0b00011000,
	    0b00011000,
	    0b00011000,
	    0b00011000,
	    0b00011000
    }};
    
    dictionary[20] = (M_Character) {'U', {
	    0b00000000,
	    0b01100110,
	    0b01100110,
	    0b01100110,
	    0b01100110,
	    0b01100110,
	    0b01100110,
	    0b00111110
    }};
    
    dictionary[21] = (M_Character) {'V', {
	    0b00000000,
	    0b01100110,
	    0b01100110,
	    0b01100110,
	    0b01100110,
	    0b01100110,
	    0b00111100,
	    0b00011000
    }};
    
    dictionary[22] = (M_Character) {'W', {
	    0b00000000,
	    0b01100011,
	    0b01100011,
	    0b01100011,
	    0b01101011,
	    0b01111111,
	    0b01110111,
	    0b01100011
    }};
    
    dictionary[23] = (M_Character) {'X', {
	    0b00000000,
	    0b01100011,
	    0b01100011,
	    0b00110110,
	    0b00011100,
	    0b00110110,
	    0b01100011,
	    0b01100011
    }};
    
    dictionary[24] = (M_Character) {'Y', {
	    0b00000000,
	    0b01100110,
	    0b01100110,
	    0b01100110,
	    0b00111100,
	    0b00011000,
	    0b00011000,
	    0b00011000
    }};
    
    dictionary[25] = (M_Character) {'Z', {
	    0b00000000,
	    0b01111110,
	    0b00000110,
	    0b00001100,
	    0b00011000,
	    0b00110000,
	    0b01100000,
	    0b01111110
    }};
    
    dictionary[26] = (M_Character) {' ', {
	    0b00000000,
	    0b00000000,
	    0b00000000,
	    0b00000000,
	    0b00000000,
	    0b00000000,
	    0b00000000,
	    0b00000000
    }};
}

char *dot_matrix_characters_lookup(char c)
{
    for (int i = 0; i < DICTIONARY_LEN; i++)
    {
        if (dictionary[i].character == c)
        {
            return dictionary[i].data;
        }
    }
    return "";
}