#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in
 * ascending order using the Bubble sort algorithm
 * @array: array of integers
 * @size: len of the array.
 **/

void bubble_sort(int *array, size_t size)
{
	int swap = 1; /* It becomes 0 when there is not swap */
	int tmp = 0;
	size_t i = 0; /* Le ponemos size_t para que sea comparable con el tipo de 'size' */

	while (swap == 1)
	{
		/* Se entra en el for siguiente siempre y cuando "swap" sea igual a 1, ya que como vemos mas
		 * adelante, seteamos swap = 1 cuando se entra en el if y se hace efectivamente el swap.
		 * Entonces si se hace un recorrido y no se hace ningun swap, no se va a setear swap en 1
		 * y entonces lo seteamos en 0 y se sale del while ya que no se vuelve a entrar porque swap
		 * es igual es 0. */
		swap = 0;
		for (i = 0; i < (size - 1); i++)
		/* Aca se recorre y se compara elementos dentro del array. 
		 * Se hace hasta "size - 1" para que no de segmentation fault al querer acceder a un espacio
		 * en memoria que no se puede. */
		{
			if (array[i] > array[i + 1])
			/* Si el elemento de la posicion 'i' es mayor al siguiente elemento, entonces hay que hacer
			 * un swap entre ambos para llevar el elemento mas grande hacia la "derecha". */
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				swap = 1;
				/* Se setea swap en 1 cada que se hace un swap */
				print_array(array, size);
				/* Nos piden en la letra del ej que vayamos imprmiendo el array siempre que se haga
				 * un swap. */
			}
		}
	}
}
