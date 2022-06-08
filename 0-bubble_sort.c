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
	size_t i = 0;

	if (array == NULL || size < 2)
		return;

	while (swap == 1)
	{
		swap = 0;
		for (i = 0; i < (size - 1); i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				swap = 1;
				print_array(array, size);
			}
		}
	}
}
