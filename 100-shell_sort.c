#include "sort.h"

/**
 * shell_sort - function that sorts an array of integers
 * in ascending order using the Shell sort algorithm,
 * using the Knuth sequence.
 * @array: array to be sorted.
 * @size: size of the array.
 **/

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, idx1 = 0, idx2 = 0;
	int swap = 0;

	if (array == NULL || size < 2)
	{
		return;
	}

	while (gap < (size / 3)) /* to calculate the start gap */
	{
		gap = (gap * 3) + 1;
	}

	while (gap > 0)
	{
		for (idx1 = gap; idx1 < size; idx1++)
		{
			swap = array[idx1];
			idx2 = idx1;

			while (idx2 > gap - 1 && swap <= array[idx2 - gap]) /* insertion sort */
			{
				array[idx2] = array[idx2 - gap];
				idx2 = idx2 - gap;
			}
			array[idx2] = swap;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
