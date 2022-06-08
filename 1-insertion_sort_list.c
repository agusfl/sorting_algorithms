#include "sort.h"

/**
 * insertion_sort_list - is a simple sorting algorithm that works similar to
 * the way you sort playing cards in your hands.
 * @list: doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = list->next;
	listint_t *prev = NULL;
	listint_t *swap = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		prev = current->prev;
		swap = current;
		if (current->n < prev->n)
		{
			prev = current;
			current = swap->prev;

		current = swap->next;
	}
}
