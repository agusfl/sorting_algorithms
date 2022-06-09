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
	if (array == NULL || size < 2)
		return;

	sort(array, size, 0, size - 1);
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
 * @array: array to be sorted.
 * @size: size of the array.
 * @start_array: first element of the array.
 * @pivot: last element of the array.
 * Return: index of the partitioned array.
 */

size_t partition(int *array, size_t size, size_t start_array, size_t pivot)
{
	size_t iter = 0;

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

/**
 * sort - function that sorts the arrays.
 * @array: array to be sorted.
 * @size: size of the array.
 * @start_array: first element of the array.
 * @pivot: last element of the array.
 * Return: index of the partitioned array.
 */

void sort(int *array, size_t size, size_t start_array, size_t pivot)
{
	size_t part = 0;

	if (start_array < pivot)
	{
		part = partition(array, size, start_array, pivot);
		sort(array, size, 0, (part - 1));
		sort(array, size, (part + 1), pivot);
	}
}

