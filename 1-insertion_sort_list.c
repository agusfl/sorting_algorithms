#include "sort.h"

/**
 * insertion_sort_list - is a simple sorting algorithm that works similar to
 * the way you sort playing cards in your hands.
 * @list: doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list);
	listint_t *swap = NULL;


	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		swap = current;
		while (current->prev != NULL && current->n < current->prev->n)
		{
			swap->prev->next = swap->next;
			if (swap->next != NULL)
			{
				swap->next->prev = swap->prev;
			}
			swap->next = swap->prev;
			swap->prev = swap->prev->prev;
			swap->next->prev = swap;
			if (swap->prev != NULL)
				swap->prev->next = swap;
			else
			{
				*list = swap;
			}
			print_list(*list);
		}
		current = current->next;
	}
}
