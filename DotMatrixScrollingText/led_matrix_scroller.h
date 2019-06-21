/*
* led_matrix_scroller.h
*
* Created: 6/21/2019 12:26:05 PM
*  Author: Ruben
*/

#ifndef LED_MATRIX_SCROLLER_H_
#define LED_MATRIX_SCROLLER_H_

//SCROLL_MODES define the rate of scrolling.
#define SCROLL_MODE_FAST 50
#define SCROLL_MODE_NORMAL 250
#define SCROLL_MODE_SLOW 1250

#define SCROLL_BUFFER_SIZE 350

//scroller_set_text sets the internal buffer with the string that should be displayed.
//@param: is a string that should be displayed on the led matrix.
void scroller_set_text(char *);

//scroller_scroll_right reads from the buffer, shifts the characters to the right and writes them to the matrix display.
void scroller_scroll_right(void);

//scroller_scroll_right reads from the buffer, shifts the characters to the left and writes them to the matrix display.
void scroller_scroll_left(void);

//scroller_clear_buffer clears the internal buffer to only 0's.
void scroller_clear_buffer(void);

//scroller_set_speed takes a SCROLL_MODE to set the rate of scrolling.
//@param : should be either SCROLL_MODE_FAST, SCROLL_MODE_NORMAL or SCROLL_MODE_SLOW.
void scroller_set_speed(int);

//scroller_get_speed returns the current SCROLL_MODE.
int scroller_get_speed(void);

#endif /* LED_MATRIX_SCROLLER_H_ */