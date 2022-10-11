#include "sort.h"


/**
 * countSortbydigit - 
 * @arr: array to be sorted
 * @radix:
 * @exp:
 * @size: size of arr
 */
void countSortbydigit(int *arr, int radix, int exp, size_t size)
{
	int bucketIndex;
	int[] buckets = new int[radix];

	// Initialize bucket
	for (int i = 0; i < radix; i++)
		buckets[i] = 0;

	// Count frequencies
	for (int i = 0; i < array.Length; i++)
	{
		bucketIndex = (int)(((array[i] - minValue) / exponent) % radix);
		buckets[bucketIndex]++;
	}

	// Compute cumulates
	for (int i = 1; i < radix; i++)
		buckets[i] += buckets[i - 1];

	// Move records
	for (int i = array.Length - 1; i >= 0; i--)
	{
		bucketIndex = (int)(((array[i] - minValue) / exponent) % radix);
		output[--buckets[bucketIndex]] = array[i];
	}

	// Copy back
	for (int i = 0; i < array.Length; i++)
		array[i] = output[i];
    }
}


/**
 * sort - sorts the
 * @arr: array to be sorted
 * @radix:
 * @size: size of array
 */
void sort(int *arr, int radix, size_t size)
{
	size_t i;
	int exp;

	int min = arr[0];
	int max = arr[0];
	for (i = 1; i < size; i++)
	{
		if (arr[i] < min)
			min = arr[i];
		else
			max = arr[i];
	}
	exp = 1;
	while ((max - min) / exp >= 1)
	{
		countSortbydigit(arr, radix, exp, min, size);
		exp *= radix;
	}
}


/**
 * radix_sort - sorts an array of integers in ascending order using
 * the Radix sort algorithm
 * @array: unsorted array
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sort(array, 10, size)
}
