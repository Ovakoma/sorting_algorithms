#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array of integers to be ordered
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	quick_sort_recur(array, 0, size - 1, size);
}

/**
 * lomuto_partition - uses the lomuto algorithm to sort elements
 * in array.
 * @arr: array to be sorted
 * @lo: index of first element of array
 * @hi: index of last element of array.
 */
int lomuto_partition(int *arr, int lo, int hi, size_t size)
{
	int pivot, i, j;

	if (lo >= hi || lo < 0)
		return (-1);

	pivot = arr[hi];
	i = lo;

	for (j = lo; j < hi; j++)
	{
		if (arr[j] <= pivot)
		{
			if (i != j && arr[i] != arr[j])
				swap_el(arr, &arr[i], &arr[j], size);
			i += 1;
		}
	}
	if (hi != lo && arr[hi] != arr[i])
		swap_el(arr, &arr[i], &arr[hi], size);
	return (i);
}

/**
 * swap_el - swaps elements in array
 * @arr: array containing elements
 * @el_1: first element
 * @el_2: second element
 * @size: size of array
 */
void swap_el(int *arr, int *el_1, int *el_2, size_t size)
{
	int tmp;

	tmp = *el_1;
	*el_1 = *el_2;
	*el_2 = tmp;

	print_array(arr, size);
}

/**
 * quick_sort_recur - recursive appraoch to quick sort
 * @arr: array passed into function to be sorted
 * @low: start index of array
 * @high: last index of array
 */
void quick_sort_recur(int *arr, int low, int high, size_t size)
{
	int pivot_idx;

	if  (low < high)
	{
		pivot_idx = lomuto_partition(arr, low, high, size);
		quick_sort_recur(arr, low, pivot_idx - 1, size);
		quick_sort_recur(arr, pivot_idx + 1, high, size);
	}
}
