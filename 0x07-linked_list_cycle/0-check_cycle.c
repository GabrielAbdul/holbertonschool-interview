#include "lists.h"

/**
 * check_cycle - check if a linked list has a cycle
 * @list: list to check
 * Return: 1 if cycle else 0
 */
int check_cycle(listint_t *list)
{
	listint_t *slow, *fast;

	if (list == NULL)
		return (0);
	slow = list;
	fast = list->next;
	while (slow && fast && fast->next)
	{
		if (fast == slow)
			return (1);
		slow = slow->next;
		fast = fast->next->next;
	}
	return (0);
}
