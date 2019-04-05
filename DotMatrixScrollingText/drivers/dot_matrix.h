/*
 * dot_matrix.h
 *
 * Created: 4/5/2019 5:23:37 PM
 *  Author: Ruben
 */

#ifndef DOT_MATRIX_H_
#define DOT_MATRIX_H_
#define DOT_MATRIX_MAX_ROWS 8
#define DOT_MATRIX_MAX_COLS 8

void dot_matrix_init(void);

void dot_matrix_clear(void);

void dot_matrix_fill(void);

void dot_matrix_draw_row(int row, int data);

/*
dot_matrix_draw_character
@param data - 
@param offset - offset indicates how 
*/
void dot_matrix_draw_character(char data[DOT_MATRIX_MAX_ROWS], uint8_t offset);

#endif /* DOT_MATRIX_H_ */