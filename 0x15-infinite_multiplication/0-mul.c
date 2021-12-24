#include "holberton.h"
/**
 * main - mul two positive numbers
 * @argc: argument count
 * @argv: string array of arguments
 * Return: 0
 */

int main(int argc, char **argv)
{

	long int num1, num2;
	int lenOne, lenTwo;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	if ((argv[1] - '0') == 0 || (argv[2] - '0') == 0)
	{
		printf("0\n");
		printf("0\n");
		return (0);
	}

	if ((_isdigit(argv[1]) == 0) && (_isdigit(argv[2]) == 0))
	{
		lenOne = _strlen(argv[1]);
		lenTwo = _strlen(argv[2]);
	}

	if ((lenOne + lenTwo) < 10)
	{
		num1 = _atoi(argv[1], lenOne);
		num2 = _atoi(argv[2], lenTwo);
		printf("%ld\n", num1 * num2);
	}

	return (0);
}


/**
 * _strlen - checks the length of the string
 * @string: a string of digits, hopefully
 * Return: the count of items in the string
 */
int _strlen(char *string)
{
	int i = 0;

	while (string[i] != '\0')
		i++;

	return (i - 1);
}

/**
 * _isdigit - make sure all chars in a string are numeric
 * @string: a string of chars
 * Return: 0 if all digits
 */
int _isdigit(char *string)
{
	int i;

	for (i = 0; string[i] != '\0'; i++)
	{
		if ((string[i] < 48) || (string[i] > 57))
		{
			printf("Error\n");
			exit(98);
		}
	}
	return (0);
}

/**
 * _atoi - convert string to integer
 * @string: string
 * @len: string length
 * Return: digit string as integer
 */
long int _atoi(char *string, int len)
{
	int i;
	long int num = 0;

	for (i = 0; i <= len; i++)
		num = (num * 10) + (string[i] - '0');

	return (num);
}
