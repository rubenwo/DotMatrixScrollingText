/*
 * text_scroller.h
 *
 * Created: 4/5/2019 5:21:48 PM
 *  Author: Ruben
 */

#ifndef TEXT_SCROLLER_H_
#define TEXT_SCROLLER_H_

#define TEXT_MAX_SIZE 255
#define TEXT_SCROLL_SPEED_SLOW 100
#define TEXT_SCROLL_SPEED_MEDIUM 50
#define TEXT_SCROLL_SPEED_FAST 10

void text_scroller_init(uint8_t initial_speed);

void text_scroller_set_scroll_speed(uint8_t speed);

void text_scroller_set_text(char text[TEXT_MAX_SIZE], size_t len);

void text_scroller_update(void);

#endif /* TEXT_SCROLLER_H_ */