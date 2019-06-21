/*
 * led_matrix_scroller.h
 *
 * Created: 6/21/2019 12:26:05 PM
 *  Author: Ruben
 */ 


#ifndef LED_MATRIX_SCROLLER_H_
#define LED_MATRIX_SCROLLER_H_

#define SCROLLING_FAST		1
#define SCROLLING_AVERAGE	4
#define SCROLLING_SLOW		8


void selectLetters(char *word);
void scrollRight(void);
void scrollLeft(void);
void clearDotmatrixBuffer(void);

void setScrollingSpeed(int adjustedSpeed);
int getScrollingSpeed(void);



#endif /* LED_MATRIX_SCROLLER_H_ */