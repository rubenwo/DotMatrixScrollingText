/*
* dictionary.h
*
* Created: 6/21/2019 12:05:09 PM
*  Author: Ruben
*/


#ifndef DICTIONARY_H_
#define DICTIONARY_H_

typedef struct letter{
	char character;
	int size;
	int structure[8];
}letter;

letter look_up(char);

#endif /* DICTIONARY_H_ */