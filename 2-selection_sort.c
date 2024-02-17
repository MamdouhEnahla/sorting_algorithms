#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: The array
 * @size: The size of the array
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, position;
	int swap;

	for (i = 0; i < (size - 1); i++)
	{
		position = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[position] > array[j])
				position = j;
		}
		if (position != i)
		{
			swap = array[i];
			array[i] = array[position];
			array[position] = swap;
			print_array(array, size);
		}
	}
}
