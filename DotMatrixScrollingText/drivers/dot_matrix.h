/*
 * dot_matrix.h
 *
 * Created: 4/5/2019 5:23:37 PM
 *  Author: Ruben
 */

#ifndef DOT_MATRIX_H_
#define DOT_MATRIX_H_
#define DOT_MATRIX_MAX_ROWS 8

void dot_matrix_init(void);

void dot_matrix_clear(void);

void dot_matrix_fill(void);

void dot_matrix_draw_row(int row, int data);

void dot_matrix_draw_character(char data[DOT_MATRIX_MAX_ROWS]);

#endif /* DOT_MATRIX_H_ */