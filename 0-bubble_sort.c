#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 * @array: array of integers to b sorted
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int tmp;
	bool swap;

	if (!array)
		return;
	
	do
	{
		swap = false;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				swap = true;
				print_array(array, size);
			}
		}
	} while(swap);
}
