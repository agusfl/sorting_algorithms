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
	size_t part = 0;
	int start_array = 0, pivot = size - 1;

	if (array == NULL || size < 2)
		return;

	if (start_array < pivot)
	{
		part = partition(array, size);

		quick_sort(array, (part - 1));
		quick_sort(array, (part + 1));
	}
}

/**
 * swap_array - function that swaps two numbers.
 * @array: array with numbers to swap
 * @num1: index of the first number to swap
 * @num2: index of the second number to swap
 * @size: size of the array
 */

void swap_array(int *array, int num1, int num2, size_t size)
{
	int tmp;

	tmp = array[num1];
	array[num1] = array[num2];
	array[num2] = tmp;
	print_array(array, size);
}

/**
 * partition - function to implement the partition of sub arrays.
 * @array: array to be sorted
 * @size: size of the array.
 * Return: index of the partitioned array.
 */

size_t partition(int *array, size_t size)
{
	size_t iter = 0, pivot = size - 1, start_array = 0;

	for (iter = start_array; iter < size - 1; iter++)
	{
		if (array[iter] <= array[pivot])
		{
			swap_array(array, start_array, iter, size);
			start_array += 1;
		}
	}
	swap_array(array, start_array, pivot, size);

	return (start_array);
}
