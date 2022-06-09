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

	/* Chequeamos que la lista que se pasa como argumento no este vacia y que tenga mas de un elemento
	 * con: (*list)->next == NULL */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		swap = current; 
		/* Seteamos swap en la posicion que se encuentre current para trabajar sobre swap y dejar "current"
		 * como puntero de recorrido, swap seria nuestro "pivot". */
		while (current->prev != NULL && current->n < current->prev->n)
		/* Este seria el control de cuantas posiciones a la izquierda hay que mover el nodo. Nos vamos
		 * a mover siempre y cuando el valor del nodo current sea menor al nodo anterior o si se llega
		 * al NULL del inicio (en dicho caso es cuando debemos detenernos, ya que llegamos al inicio). */
		{
			swap->prev->next = swap->next; 
			/* Cambiamos el puntero next de la posicion anterior al puntero en el que estamos parados
			 * (prev del actual) asignandole el nodo siguiente (swap->next) al actual en el que
			 * estamos parados. */
			if (swap->next != NULL)
			/* Se controla si el nodo siguiente a donde esta parado el pivot "swap" no es NULL, si
			 * no es NULL cambiamos el puntero prev del nodo siguiente al que se encuentra apuntando
			 * "swap". Si es NULL lo dejamos como esta porque significa que es el final de la lista. */
			{
				swap->next->prev = swap->prev;
			}
			swap->next = swap->prev;
		       	/* Le asignamos al puntero next de nuestro nodo actual "swap" al puntero anterior. */
			swap->prev = swap->prev->prev;
			/* Ahora asignamos el puntero prev de "swap" para que sea el prev del prev, osea el numero
			 * de la izquierda. */
			swap->next->prev = swap;
			/* Aca se modifica el puntero prev del nodo siguiente al que modificamos para que apunte
			 * para atras hacia el nodo que tomo su posicion recientemente que seria swap. */
			if (swap->prev != NULL)
				swap->prev->next = swap;
			/* Se hace un control similar al que habiamos hecho al principio pero para el inicio de la
			 * lista, para ver si ya se llego al NULL y entender que ya se llego a la posicion incial.*/
			else
			{
				*list = swap; /* Modificamos lo que seria el "head" de la lista */
			}
			print_list(*list);
		}
		current = current->next; /* traversamos la lista */
	}
}
