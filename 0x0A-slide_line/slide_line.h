#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define SLIDE_LEFT 'l'
#define SLIDE_RIGHT 'r'

int slide_line(int *line, size_t size, int direction);
int *add_right(int *line, size_t size);
int *add_left(int *line, size_t size);
void selection_sort_right(int *array, size_t size);
void selection_sort_left(int *array, size_t size);


#endif /* SLIDE_LINE_H */
