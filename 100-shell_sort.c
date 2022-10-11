#include "sort.h"

/**
 * swapVal - simple swap function to swap values of array.
 * @arr: array given
 * @val_1: first value
 * @val_2: second value
 */
void swapVal(int *arr, int val_1, int val_2)
{
	int tmp;

	if (arr[val_1] != arr[val_2])
	{
		tmp = arr[val_1];
		arr[val_1] = arr[val_2];
		arr[val_2] = tmp;
	}
}

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: array to be sorted.
 * @size: size of array.
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, n = 1;

	if (size < 2)
		return;
	while (n <= size / 3)
		n = n * 3 + 1;
	while (n >= 1)
	{
		for (i = 0; i < size; i++)
			for (j = i; j >= n && array[j] < array[j - n]; j -= n)
				swapVal(array, j, j - n);
		n /= 3;
		print_array(array, size);
	}
}
