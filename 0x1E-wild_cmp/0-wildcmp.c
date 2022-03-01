#include "holberton.h"

/**
 * wildcmp - compares two strings and returns 1 if
 * the strings can be considered identical otherwise return 0.
 * @s1: string one
 * @s2: string two, can contain the special character '*'
 *      The special char * can replace any string (including an empty string)
 * Return: 1 if strings identical, else 0
 */
int wildcmp(char *s1, char *s2)
{
	/* TODO r = wildcmp("abc", "*b"); */

	int index;

	if (*(s1) == '\0')
	{

		if (*(s2) == '*')
			return (wildcmp(s1, s2 + 1));
		else if (*(s2) == '\0')
			return (1);
		else
			return (0);
	}

	if (*(s2) == '\0')
	{
		if (s1 != NULL)
			return (0);
		return (1);
	}

	if (*(s1) == *(s2))
		return (wildcmp(s1 + 1, s2 + 1));
	else if (*(s2) == '*')
	{
		index = find_index(s1, *(s2 + 1), 0);
		wildcmp(s1 + index, s2 + 1);
	}
	else if (*(s2) != *(s1))
		return (0);
	return (1);
}
/**
 * find_index - finds index of 'ch' occurence in 'string'
 * @string: string to search
 * @ch: character to search for
 * @index: index to return
 * Return: index of ch in string
 */
int find_index(char *string, char ch, int index)
{
	if (string == NULL)
		return (-1);
	if (*(string) == ch)
		return (index);
	index += 1;
	return (find_index(string + 1, ch, index));
}
