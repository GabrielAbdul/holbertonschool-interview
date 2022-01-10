#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list, floyd's algo
 * @head: pointer to head of list
 * Return: Node where loop is detected
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *s, *f;

	if (head == NULL)
		return (NULL);

	s = head;
	f = head;

	while (s && f && f->next)
	{
		s = s->next;
		f = f->next->next;
		if (s == f)
			return (f);
	}
	return (NULL);
}
