/*
* led_matrix_scroller.h
*
* Created: 6/21/2019 12:26:05 PM
*  Author: Ruben
*/

#ifndef LED_MATRIX_SCROLLER_H_
#define LED_MATRIX_SCROLLER_H_

#define SCROLL_MODE_FAST 50
#define SCROLL_MODE_NORMAL 250
#define SCROLL_MODE_SLOW 1250

void scroller_set_text(char *);
void scroller_scroll_right(void);
void scroller_scroll_left(void);
void scroller_clear_buffer(void);

void scroller_set_speed(int);
int scroller_get_speed(void);

#endif /* LED_MATRIX_SCROLLER_H_ */