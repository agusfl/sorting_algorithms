#include "sort.h"

/**
 * cocktail_sort_list - The algorithm extends bubble sort by operating in two
 * directions
 * @list: doubly linked list to be ordered
 */

void cocktail_sort_list(listint_t **list)
{
	int swap = 1; /* It becomes 0 when there is not swap */
	listint_t *current = NULL, *tmp = NULL;

	if (!list)
		return;
	current = *list;
	while (swap == 1)
	{
		swap = 0;
		while (current->next != NULL)
		{
			tmp = current;
			if (current->n > current->next->n)
			{
				if (current->prev != NULL)
					tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev, tmp->next = tmp->next->next;
				if (current->prev == NULL)
				{
					tmp->prev = tmp->next->prev, *list = tmp->prev;
				}
				else
					tmp->prev = tmp->prev->next;
				tmp->prev->next = tmp;
				if (tmp->next != NULL)
					tmp->next->prev = tmp;
				swap = 1, print_list(*list);
			}
			else
				current = current->next;
		}
		while (current->prev != NULL)
		{
			tmp = current;
			if (current->n < current->prev->n)
				swap = swap_left(list, current);
			else
				current = current->prev;
		}
	}
}

/**
 * swap_left - traverse a doubly linked list from the bottom
 * to the top and sort the numbers using the cocktail sort algorithm
 * @list: list to traverse.
 * @current: last node position.
 * Return: 1 if there was a swap 0 otherwise.
**/

int swap_left(listint_t **list, listint_t *current)
{
	listint_t *tmp = NULL;
	int swap = 0;

	tmp = current;

	tmp->prev->next = tmp->next;
	if (tmp->next != NULL)
	{
		tmp->next->prev = tmp->prev;
	}
	tmp->next = tmp->prev;
	tmp->prev = tmp->prev->prev;
	tmp->next->prev = tmp;
	if (tmp->prev != NULL)
	{
		tmp->prev->next = tmp;
	}
	else
	{
		*list = tmp;
	}
	swap = 1;
	print_list(*list);
	return (swap);
}
