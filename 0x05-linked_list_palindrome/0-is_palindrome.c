#include "lists.h"

/**
 * is_palindrome - determines if linked list is palindrome
 * O(n) time | O(1) Space - n number of nodes in linked list
 * @head: head of list
 * Return: 1 if linked list is palindrome else 0 
 */
int is_palindrome(listint_t **head)
{
    listint_t *first, *second;
    listint_t *slow = *head, *fast = *head;

    /* at end of loop slow will be the middle node */
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    /* reverse the list on the middle node to get head of second list */
    second = reverseLinkedList(slow);
    first = *head;

    while (second)
    {
        if (second->n != first->n)
            return (false);
        second = second->next;
        first = first->next;
    }
    return (true);
}

/**
 * reverseLinkedList - function that reverses a linked list
 * @head: head of list to reverse
 * Return: head of reversed list
 */
listint_t *reverseLinkedList(listint_t *head)
{
    listint_t *prev = NULL, *current = head, *next;

    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return (prev);
}