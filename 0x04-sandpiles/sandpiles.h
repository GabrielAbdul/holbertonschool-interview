#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>

#define IS_TOP ((i == 0 && j == 1))
#define IS_LEFT ((i == 1 && j == 0))
#define IS_RIGHT ((i == 1 && j == 2))
#define IS_BOTTOM ((i == 2 && j == 1))
#define IS_MIDDLE ((i == 1 && j == 1))
#define IS_CORNER ((i == 0 || i == 2) && (j == 0 || j == 2))

#define TOP_LEFT ((i == 0) && (j == 0))
#define BOTTOM_LEFT ((i == 2) && (j == 0))
#define TOP_RIGHT ((i == 0) && (j == 2))
#define BOTTOM_RIGHT ((i == 2) && (j == 2))

int unstable(int grid[3][3]);
void operate_corners(int grid[3][3], int i, int j);
static void print_grid(int grid[3][3]);
void topple_sandpile(int grid[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

#endif /* SANDPILES_H */
