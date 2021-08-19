#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: sandpile 1
 * @grid2: sandpile 2
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, b = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] != 0)
			{
				b = 1;
				break;
			}
		}
		if (i == 2 && j == 2 && b == 0)
		{
			printf("=\n");
			print_grid(grid1);
			return;
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid2[i][j] != 0)
				break;
		}
		if (i == 2 && j == 2 && b == 0)
		{
			printf("=\n");
			print_grid(grid2);
			return;
		}
	}
	/* add each index of the sandpiles together */
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
	if (unstable(grid1))
		printf("=\n"), print_grid(grid1), topple_sandpile(grid1);

}

/**
 * topple_sandpile - topples a sandpile
 * @grid: sandpile
 */
void topple_sandpile(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
			{
				grid[i][j] -= 4;
				if (IS_CORNER)
					operate_corners(grid, i, j);
				else if (IS_MIDDLE)
				{
					grid[i + 1][j]++;
					grid[i - 1][j]++;
					grid[i][j + 1]++;
					grid[i][j - 1]++;
				}
				else if (IS_TOP || IS_BOTTOM)
				{
					grid[1][1]++;
					grid[i][j - 1]++;
					grid[i][j + 1]++;
				}
				else if (IS_LEFT || IS_RIGHT)
				{
					grid[1][1]++;
					grid[i - 1][j]++;
					grid[i + 1][j]++;
				}
			}
	if (unstable(grid))
		printf("=\n"), print_grid(grid), topple_sandpile(grid);
}

/**
 * operate_corners - operates on corners of sandpiles
 * @grid: sandpile
 * @i: the position of rows
 * @j: the position of columns
 */
void operate_corners(int grid[3][3], int i, int j)
{
	if (TOP_LEFT)
	{
		grid[i + 1][j]++;
		grid[i][j + 1]++;
	}
	else if (BOTTOM_LEFT)
	{
		grid[i - 1][j]++;
		grid[i][j + 1]++;
	}
	else if (TOP_RIGHT)
	{
		grid[i][j - 1]++;
		grid[i + 1][j]++;
	}
	else if (BOTTOM_RIGHT)
	{
		grid[i - 1][j]++;
		grid[i][j - 1]++;
	}
}

/**
 * unstable - checks if a sandpile is unstable
 * @grid: sandpile
 * Return: 1 or 0
 */
int unstable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (1);
		}
	}
	return (0);
}
