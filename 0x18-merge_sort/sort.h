#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void merge(int *arry, int *arr, int start, int mid, int end);
void split_merge(int *array, int start, int end, int *arr);
void merge_sort(int *array, size_t size);

#endif /* SORT_H */