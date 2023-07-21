#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: doubly linked list of integers
 * Return: void
*/
void insertion_sort_list(listint_t **list)
{
listint_t *current = NULL;
listint_t *next = NULL;
listint_t *prev = NULL;
listint_t *tmp = NULL;
if (!list || !(*list) || !(*list)->next)
return;
current = *list;
while (current)
{
next = current->next;
prev = current->prev;
if (prev && prev->n > current->n)
{
tmp = prev;
while (tmp && tmp->n > current->n)
{
tmp->next = current->next;
if (tmp->next)
tmp->next->prev = tmp;
current->next = tmp;
current->prev = tmp->prev;
if (current->prev)
current->prev->next = current;
tmp->prev = current;
tmp = current->prev;
if (!tmp)
*list = current;
print_list(*list);
}
}
current = next;
}
}
