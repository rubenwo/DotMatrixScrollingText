/*
 * DotMatrixScrollingText.c
 *
 * Created: 4/5/2019 4:54:37 PM
 * Author : Ruben
 */
#define GLOBAL_UPDATE_RATE 10
#define F_CPU 16000000L

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>

#include "drivers/i2c.h"

#include "logic/text_scroller.h"

int main(void)
{
	char* text = "Nerds are the new cool";
    i2c_init();

    text_scroller_init(TEXT_SCROLL_SPEED_FAST);
    text_scroller_set_text(text, strlen(text));
    while (1)
    {
        text_scroller_update();
        _delay_ms(GLOBAL_UPDATE_RATE);
    }
}
