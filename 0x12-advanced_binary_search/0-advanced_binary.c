#include "search_algos.h"

/**
 * print_array - prints array we are about to search
 * @array: input array of sorted ints
 * @l: left edge of array (index)
 * @r: right edge of array (index)
 */
void print_array(int *array, int l, int r)
{
	int i;

	printf("Searching in array: ");
	for (i = l; i < r; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);
}

/**
 * advanced_binary_recursion - search for a value in a sorted array of integers
 * @array: sorted int array
 * @l: leftmost index of array
 * @r: rightmost index of array
 * @value: value we're searching for
 * Return: index where @value is located or -1 on failure
 */
int advanced_binary_recursion(int *array, int l, int r, int value)
{
	int mid;

	if (l > r)
		return (-1);

	print_array(array, l, r);

	/* if we've traversed entire array element equals value, return index */
	if (l == r && array[r] == value)
		return (r);

	/* if traversed entire array, and element does not equal value, return -1 */
	if (l == r && array[r] != value)
		return (-1);

	mid = l + (r - l) / 2;

	/* ensure we're at the first occurence of value in array */
	if ((l == mid || value != array[mid - 1]) && array[mid] == value)
	{
		/* array[mid] == value return index represented by mid */
		return (mid);
	}

	if (array[mid] >= value)
		return (advanced_binary_recursion(array, l, mid, value));
	return (advanced_binary_recursion(array, mid + 1, r, value));
}

/**
 * advanced_binary - wrapper function
 * @array: sorted int array
 * @size: size of input array
 * @value: value we're searching for
 * Return: index where @value is located or -1 on failure
 */
int advanced_binary(int *array, size_t size, int value)
{

	if (!array || size == 0)
		return (-1);

	return (advanced_binary_recursion(array, 0, size - 1, value));
}
