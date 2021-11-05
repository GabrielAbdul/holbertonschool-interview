#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers.
 * @list: list
 * @value: value we're searching for
 * Return: int
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *c, *p;

	if (!list)
		return (NULL);

	c = list->express;
	p = list;
	/* traverse express lane */
	while (c)
	{
		printf("Value checked at index [%lu] = [%d]\n", c->index, c->n);
		if (c->n >= value)
			break;
		p = c;
		if (c->express == NULL)
		{
			while (c->next)
				c = c->next;
			break;
		}
		c = c->express;
	}
	printf("Value found between indexes [%lu] and [%lu]\n", p->index, c->index);
	while (p && p->index <= c->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", p->index, p->n);
		if (p->n == value)
			return (p);
		p = p->next;
	}
	return (NULL);
}
