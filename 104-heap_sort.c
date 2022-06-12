#include "sort.h"

/**
 * heap_sort - function that sorts an array of
 * integers in ascending order using the Heap sort algorithm
 * @array: array to be sorted.
 * @size: size of the array.
 **/

void heap_sort(int *array, size_t size)
{
	int idx1 = 0, idx2 = 0;
	size_t len_array = size;

	/* create the max heap */
	for (idx1 = (size / 2) - 1; idx1 >= 0; idx1--)
	{
		heapify(array, size, idx1, len_array);
	}
	/* sorting with swap */
	for (idx2 = size - 1; idx2 >= 0; idx2--)
	{
		swap_array(array, len_array, 0, idx2);
		heapify(array, idx2, 0, len_array);
	}
}

/**
 * heapify - looks for the max value and make it the maxheap,
 * using the sift-down implementation,
 * it applies for the root and the childs.
 * @array: array to be sorted.
 * @size: size of the array.
 * @len_array: lenght of the original array.
 * @max: index of the maxheap.
 **/

void heapify(int *array, size_t size, size_t max, size_t len_array)
{
	size_t max_heap = max;
	size_t left = (2 * max) + 1;
	size_t right = (2 * max) + 2;

	if (left < size && array[left] > array[max_heap])
	{
		max_heap = left;
	}
	if (right < size && array[right] > array[max_heap])
	{
		max_heap = right;
	}
	if (max_heap != max) /* base case */
	{
		swap_array(array, len_array, max, max_heap);
		heapify(array, size, max_heap, len_array); /* recursive call */
	}
}

/**
 * swap_array - function that swaps two numbers.
 * @array: array with numbers to swap
 * @size: size of the array
 * @num1: index of the first number to swap
 * @num2: index of the second number to swap
 **/

void swap_array(int *array, size_t size, int num1, int num2)
{
	int tmp;

	tmp = array[num1];
	array[num1] = array[num2];
	array[num2] = tmp;
	if (tmp != array[num1])
		print_array(array, size);
}
