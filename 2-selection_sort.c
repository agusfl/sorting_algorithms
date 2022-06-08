#include "sort.h"

/**
  * selection_sort - algorithm that sorts an array by repeatedly finding the
  * minimum element (considering ascending order) from unsorted part and
  * putting it at the beginning. The algorithm maintains two subarrays in a
  * given array.
  * @array: the array to be sorted
  * @size: size of the array
  */

void selection_sort(int *array, size_t size)
{
	size_t iter = 0, idx = 0;
	int min_num = 0, tmp = 0, lowest_value = 0;

	if (array == NULL || size < 2)
		return;

	for (iter = 0; iter < (size - 1); iter++)
	{
		min_num = array[iter]; /* assume min num is the first element of the array */
		for (idx = iter + 1; idx < size; idx++)
		{
			if (array[idx] < min_num) /* search for the min number (lowest value) */
			{
				min_num = array[idx];
				lowest_value = idx;
			}
		}
		tmp = array[iter];
		if (tmp != min_num) /* swap values */
		{
			array[iter] = array[lowest_value];
			array[lowest_value] = tmp;
			print_array(array, size);
		}
	}
}
