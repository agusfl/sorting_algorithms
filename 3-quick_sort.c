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
 * @size: size of the array
 * @num1: index of the first number to swap
 * @num2: index of the second number to swap
 */

void swap_array(int *array, size_t size, int num1, int num2)
{
	int tmp;

	tmp = array[num1];
	array[num1] = array[num2];
	array[num2] = tmp;
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

	for (iter = start_array; iter < end_array; iter++)
	{
		if (array[iter] <= pivot)
		{
			swap_array(array, size, swap, iter);
			swap++;
		}
	}
	swap_array(array, size, swap, end_array);

	return (swap);
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

	if (start_array < end_array)
	{
		part = partition(array, size, start_array, end_array);
		sort(array, size, start_array, (part - 1));
		sort(array, size, (part + 1), end_array);
	}
}
