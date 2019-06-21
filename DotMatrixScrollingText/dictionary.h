/*
* dictionary.h
*
* Created: 6/21/2019 12:05:01 PM
*  Author: Ruben
*/

#ifndef DICTIONARY_H_
#define DICTIONARY_H_
#define DICTIONARY_SIZE 29

//character is a struct defining the letter, the size of the letter and its structure for the dot-matrix display.
//letter is a human readable char like 'A'.
//size is the amount of columns the letter will take up in the matrix display.
//matrix_structure is an int[] containing the data for the matrix display.
typedef struct character
{
	char letter;
	int size;
	int matrix_structure[8];
} character;

//look_up_character is a function to get the character based on the letter.
//@param : the character to lookup
//@return: Returns the character from the dictionary. if not found returns an 8x5 block.
character look_up_character(char);

#endif /* DICTIONARY_H_ */