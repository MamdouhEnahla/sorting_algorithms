#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - Prints a list of integers
 *
 * @array: The array
 * @size: The size of the array
 */

void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i, j;

	if (array && size)
	{
		for (i = 0; i < size - 1; i++)
		{
			for (j = 0; j < size - i - 1; j++)
			{
				if (array[j] > array[j + 1])
				{
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
					print_array(array, size);
				}
			}
		}
	}
}
