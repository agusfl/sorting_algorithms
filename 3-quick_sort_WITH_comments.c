#include "sort.h"

/**
 * quick_sort - is a Divide and Conquer algorithm. It picks an element as pivot
 * and partitions the given array around the picked pivot, we use the Lomuto
 * partition scheme.
 * @array: array to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2) /* Chequeamos condicion de letra */
		return;

	sort(array, size, 0, size - 1);
	/* Se llama a la funcion sort que llama a partition */
}

/**
 * swap_array - function that swaps two numbers.
 * @array: array with numbers to swap
 * @size: size of the array
 * @num1: index of the first number to swap
 * @num2: index of the second number to swap
 */

void swap_array(int *array, size_t size, int num1, int num2)
/* Funcion para swapear dos valores entre si */
{
	int tmp;

	tmp = array[num1];
	array[num1] = array[num2];
	array[num2] = tmp;
	/* Hacemos un if para que no se impriman cuando quedan los elementos separados
	 * de a uno, osea en un sub array, ya que nosotros queremos imprimir solo en
	 * los swaps.
	 * Si el indice del primer numero a swapear es igual al indice del segundo numero siginifica que ya se
	 * separo en un sub array de 1 y por lo tanto no es necesario imprimir. */
	if (num1 != num2)
	{
		print_array(array, size);
	}
}

/**
 * partition - function to implement the partition of sub arrays.
 * @array: array to be sorted.
 * @size: size of the array
 * @start_array: index of first element of the array.
 * @end_array: index of last element of the array.
 * Return: index of the partitioned array.
 */

int partition(int *array, size_t size, int start_array, int end_array)
{
	int iter, swap = start_array, pivot = array[end_array];
	/* start_array es el indice 0 el primer elemento del array.
	 * end_array es el size - 1 (es el ultimo indice, size - 1 ya que se arranca a contar de 0 por lo tanto
	 * si queremos ver la ultima posicion accedemos con size - 1).
	 * pivot - es el valor de la posicion del ulitmo elemento del array. */

	for (iter = start_array; iter < end_array; iter++)
	{
		if (array[iter] <= pivot)
		/* Vamos comparando el valor de la posicion en la que esta iter en el array contra pivot (valor
		 * del ultimo elemento del array) para ver si hay que hacer swap o no. */
		{
		/* En caso que el elemento de la posicion iter del array sea menor o igual a pivot hacemos swap y
		 * e incrementamos swap (solo cuando se hace un swap), antes estabamos incremendo "iter" aca en lugar
		 * de swap lo cual nos ocasionaba problemas ya que "iter" itera hasta que iter(que es 0 al inicio
		 * porque es el indice del principio del array) sea menor a la ultima posicion del array
		 * y no siempre que se hace un swap, "iter" itera mas veces que swap. */
			swap_array(array, size, swap, iter);
			swap++;
		}
	}
	swap_array(array, size, swap, end_array);
	/* Aca se hace el swap para el pivot (end_array) */

	return (swap); /* Se retorna el numero en el que quedo la variable contadora de swaps "swap" para cuando
			  se llame con recursividad a partition en la funcion de mas abajo "sort". Esto sirve
			  para ir incrementendo y decrementando la variable "part" de la funcion partition. */
}

/**
 * sort - function that sorts the arrays.
 * @array: array to be sorted.
 * @size: size of the array.
 * @start_array: index offirst element of the array.
 * @end_array: index of last element of the array.
 * Return: index of the partitioned array.
 */

void sort(int *array, size_t size, int start_array, int end_array)
{
	int part;

	if (start_array < end_array) /* Esta es la condicion base para la recursividad, una vez que el start_array
					sea menor a end_array se va a cumplir la condicion base. */
	{
		part = partition(array, size, start_array, end_array);
		/* Se llama recursivamente a partition en sort para lo que seria los sub arrays del lado "izquierdo"
		 * del array principal. Con: part - 1 -> se le indica que el end_array va a ir decrementando de a 1
		 * en cada llamado asi lo vamos "corriendo hacia la izquierda" los sub arrays.*/
		sort(array, size, start_array, (part - 1));
		/* Se llama recursivamente a partition en sort pero en este caso para los sub arrays del lado "derecho"
		 * del array principal. Con: part + 1 -> se le indica en este caso el "start_array" y aca lo vamos
		 * "moviendo para la derecha" los sub arrays. */
		sort(array, size, (part + 1), end_array);
	}
}
