#include "menger.h"

/**
 * menger - draws a 2D Menger Sponge
 * @level: level of the Menger Sponge to draw
 */
void menger(int level)
{
	int col, row, size;

	if (level < 0)
		exit(EXIT_FAILURE);

	/* The size of a level N Menger sponge is calculated as follows: 3^N */
	size = pow(3, level);
	for (col = 0; col < size; col++)
	{
		for (row = 0; row < size; row++)
			putchar(draw_sponge(col, row));
		printf("\n");
	}
}

/**
 * draw_sponge - draws sponge one character at a time
 * @col: column
 * @row: row
 * Return: '#' or ' '
 */
char draw_sponge(int col, int row)
{
	while (col && row)
	{
		if (col % 3 == 1 && row % 3 == 1)
			return (' ');
		row /= 3;
		col /= 3;
	}

	return ('#');
}
