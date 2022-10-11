#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: unsorted array
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int j;
	size_t i, tmp, total = 0;
	int *count, *s_array, k = array[0];

	if (size < 2)
		return;

	s_array = malloc(sizeof(int) * size);
	if (!s_array)
		return;
	for (i = 0; i < size; i++)
	{
		s_array[i] = array[i];
		if (array[i] > k)
			k = array[i];
	}
	
	count = malloc(sizeof(int) * (k + 1));
	if (!count)
	{
		free(s_array);
		return;
	}
	for (j = 0; j <= k; j++)
		count[j] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (j = 0; j <= k; j++)
	{
		tmp = count[j];
		count[j] = total;
		total += tmp;
	}
	for (i = 0; i < size; i++)
		array[count[s_array[i]]++] = s_array[i];
	
	print_array(count, k + 1);
	free(count);
	free(s_array);
}
