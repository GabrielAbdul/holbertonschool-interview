#include "slide_line.h"

/**
 * slide_line - slides and mergers an arary of integers
 * @line: line of ints to slide and merge
 * @size: size of input array
 * @direction: diretion to slide and merge
 * Return: int
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line)
		return (0);

	switch (direction)
	{
		case (SLIDE_LEFT):
			line = add_left(line, size);
			selection_sort_left(line, size);
			return (1);
		case (SLIDE_RIGHT):
			line = add_right(line, size);
			selection_sort_right(line, size);
			return (1);
		default:
			return (0);
	}
}

/**
 * add_right - slides and mergers an array of
 * intergers to the right
 * @line: input int array
 * @size: size of input array
 * Return: 1
 */
int *add_right(int *line, size_t size)
{
	int num, flag = 1;
	size_t i;

	if (size == 1)
		return (line);

	for (i = 0; i < size - 1; i++)
	{

		if ((line[i] == line[i + 1]) && line[i] != 0)
		{
			line[i + 1] += line[i];
			line[i] = 0;
			i++;
			continue;
		}
		if (line[i] != 0 && flag != 0)
		{
			if (line[i] != line[i + 1])
				continue;
			num = line[i];
			line[i] = 0;
			flag = 0;
			continue;
		}

		if (num == line[i])
		{
			line[i] += num;
			flag = 1;
		}
	}
	return (line);
}

/**
 * add_left - slides and mergers an array of intergers to the left
 * @line: input int array
 * @size: size of input array
 * Return: line
 */
int *add_left(int *line, size_t size)
{
	int num, flag;
	size_t i;

	if (size == 1)
		return (line);

	for (i = size - 1; (int)i >= 0; i--)
	{
		if ((line[i] == line[i - 1]) && line[i] != 0)
		{
			line[i - 1] += line[i];
			line[i] = 0;
			i--;
			continue;
		}
		if (line[i] != 0 && flag != 0)
		{
			num = line[i];
			line[i] = 0;
			flag = 0;
			continue;
		}

		if (num == line[i])
		{
			line[i] += num;
			flag = 1;
		}
	}
	return (line);
}

/**
 * selection_sort_right - sort via selection
 * @array: array to sort
 * @size: size of array
 *
 * Return: void
 */
void selection_sort_right(int *array, size_t size)
{
	size_t i, current, min;
	int temp;

	if (array == NULL || size < 2)
		return;
	/* loop thorugh array via size */
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		/* set min to first element of array */
		/* loop through array subtracting one index everytime */
		/* check current index vs min if current < min, min = current */
		for (current = i + 1; current < size; current++)
		{
			if (array[current] < array[min])
				min = current;
		}
		/* if index i is not the same as min swap with new min */
		if (i != min)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
		}
	}
}
/**
 * selection_sort_left - sort via selection
 * @array: array to sort
 * @size: size of array
 *
 * Return: void
 */
void selection_sort_left(int *array, size_t size)
{
	size_t i, current, min;
	int temp;

	if (array == NULL || size < 2)
		return;
	/* loop thorugh array via size */
	for (i = size - 1; i > 0; i--)
	{
		min = i;
		/* set min to last element of array */
		/* loop through array subtracting one index everytime */
		/* check current index vs min if current < min, min = current */
		for (current = i - 1; current > 0; current--)
		{
			if (array[current] > array[min])
				min = current;
		}
		/* if index i is not the same as min swap with new min */
		if (i != min)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
		}
	}
}
