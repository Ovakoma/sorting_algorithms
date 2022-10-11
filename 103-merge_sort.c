#include "sort.h"

/**
 * merge - sorts and merges the various sub arrays
 * @start: starting index of the array(inclusive) for left array
 * @mid: end index(exclusive) for left array and starting index
 * (inclusive) for right array
 * @end: last index(exclusive) for right array
 * @src: unsorted array
 * @dest: is going to be merged and sorted array
 */
void merge(size_t start, size_t mid, size_t end, int *src, int *dest)
{
	size_t i, j, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(src + start, mid - start);
	printf("[right]: ");
	print_array(src + mid, end - mid);

	for (i = start, j = mid; i < mid && j < end; k++)
		if (src[i] < src[j])
			dest[k] = src[i++];
		else
			dest[k] = src[j++];
	while (i < mid)
	{
		dest[k++] = src[i];
		i++;
	}
	while (j < end)
	{
		dest[k++] = src[j];
		j++;
	}
	for (i = start, k = 0; i < end; i++)
		src[i] = dest[k++];

	printf("[Done]: ");
	print_array(src + start, end - start);
}


/**
 * splitMerge - splits the array into two runs and merges both runs
 * @array: unsorted array
 * @start: beginning index of array
 * @end: final index of the array
 * @arr: work array
 */
void splitMerge(size_t start, size_t end, int *array, int *arr)
{
	size_t mid;

	if (end - start <= 1)
		return;
	mid = start + (end - start) / 2;
	splitMerge(start, mid, array, arr);
	splitMerge(mid, end, array, arr);
	merge(start, mid, end, array, arr);
}


/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: unsorted array
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *arr;

	if (!array || size <= 1)
		return;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return;

	splitMerge(0, size, array, arr);
	free(arr);
}
