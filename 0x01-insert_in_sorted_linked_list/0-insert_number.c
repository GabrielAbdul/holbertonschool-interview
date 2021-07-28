#include "lists.h"

/**
 * insert_node - inserts node into a sorted list
 * @head: head of list
 * @number: number of node
 * Return: node we add
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *node = malloc(sizeof(listint_t)), *tmp = NULL;


    if (!node)
        return (NULL);

    node->n = number;

    if (*head == NULL || (*head)->n > number)
    {
        node->next = (*head)->next;
        *head = node;
        return (*head);
    }
        
    tmp = *head;
    while (tmp->next && tmp->next->n < number)
        tmp = tmp->next;

    node->next = tmp->next;
    tmp->next = node;
    return (node);
}