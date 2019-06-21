/*
* dictionary.h
*
* Created: 6/21/2019 12:05:01 PM
*  Author: Ruben
*/

#ifndef DICTIONARY_H_
#define DICTIONARY_H_

typedef struct character
{
	char letter;
	int size;
	int matrix_structure[8];
} character;

character look_up_character(char);

#endif /* DICTIONARY_H_ */