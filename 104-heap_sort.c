#include "sort.h"


/**
 * siftDown - repairs the heap whos element is at index 'start'
 * @arr: array to be sorted
 * @e1: first element to be swapped
 * @e2: element to be swapped with e1
 * @rSize: size of array
 */
void swap(int *arr, int e1, int e2, const int rSize)
{
	int tmp;
	(void)rSize;

	if (e1 != e2)
	{
		tmp = arr[e1];
		arr[e1] = arr[e2];
		arr[e2] = tmp;
		print_array(arr, (size_t)rSize);
	}
}


/**
 * heapify - puts elements of array, arr in heap order, in place.
 * @arr: array to be ordered
 * @size: size of array
 * @i: largest element
 * @rSize: constant int size for convenience
 */
void heapify(int *arr, size_t size, size_t i, const int rSize)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < size && arr[left] > arr[largest])
		largest = left;
	if (right < size && arr[right] > arr[largest])
		largest = right;
	if (largest != i)
	{
		swap(arr, i, largest, rSize);
		heapify(arr, size, largest, rSize);
	}
}


/**
 * heap_sort - sorts an array of integers in ascending order using
 * the Heap sort algorithm
 * @array: unsorted array
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	const int rSize = (const int)size;
	int i;

	if (!array || size < 2)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, rSize);
	for (i = size - 1; i >= 0; i--)
	{
		swap(array, 0, i, rSize);
		heapify(array, i, 0, rSize);
	}
}
