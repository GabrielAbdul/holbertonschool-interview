#include "palindrome.h"

/**
 * is_palindrome - checkes if an int is a palindrome
 * @n: integer
 * Return: if palindrome 1, else 0
 */
int is_palindrome(unsigned long n)
{
	unsigned long tmp = 0;
	unsigned long num = 0;

	/* 0 is a palindrome */
	if (n == 0)
		return (1);

	/* copy the input to operate on*/
	tmp = n;

	while (tmp)
	{
		/* retrieve last digit from m */
		int last = tmp % 10;

		/* rebuild the number 1 digit at a time*/
		num = (num * 10) + last;

		/* removing last digit from n because we just operated on it */
		tmp /= 10;
	}
	/* new number same as input? yes return 1, else 0 */
	return (num == n ? 1 : 0);
}
