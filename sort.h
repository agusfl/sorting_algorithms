#ifndef SORT_H
#define SORT_H

/* Include libraries */
#include <stdio.h>
#include <stdlib.h>

/* Data structure for doubly linked list*/

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node.
 * @prev: Pointer to the previous element of the list.
 * @next: Pointer to the next element of the list.
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Prototype implementation of sorting functions */

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

/* Prototype auxiliar functions */

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap_array(int *array, size_t size, int num1, int num2);
int partition(int *array, size_t size, int start_array, int pivot);
void sort(int *array, size_t size, int start_array, int pivot);
void heapify(int *array, size_t size, size_t max, size_t len_array);
int swap_left(listint_t **list, listint_t *current);

#endif
