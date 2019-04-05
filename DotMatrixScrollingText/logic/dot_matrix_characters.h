/*
 * dot_matrix_characters.h
 *
 * Created: 4/5/2019 5:24:17 PM
 *  Author: Ruben
 */

#ifndef DOT_MATRIX_CHARACTERS_H_
#define DOT_MATRIX_CHARACTERS_H_

#define M_CHARACTER_LEN 8
#define DICTIONARY_LEN 27

typedef struct M_Character
{
    char character;
    char data[M_CHARACTER_LEN];
} M_Character;

void dot_matrix_characters_dictionary_init(void);

char *dot_matrix_characters_lookup(char c);

#endif /* DOT_MATRIX_CHARACTERS_H_ */