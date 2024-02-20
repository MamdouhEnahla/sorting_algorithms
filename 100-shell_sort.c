#include "sort.h"

/**
 * calculate_gap - Calculates the initial gap.
 * @size: Size of the array.
 * Return: Initial gap.
 */
size_t calculate_gap(size_t size)
{
	size_t gap = 1;

	while (gap < size)
		gap = gap * 3 + 1;

	return (gap);
}

/**
 * shell_sort - Sorts an array using the Shell sort.
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = calculate_gap(size);

	while (gap > 0)
	{
		for (size_t i = gap; i < size; ++i)
		{
			int temp = array[i];
			size_t j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}

			array[j] = temp;
		}

		printf("Array after interval %zu:\n", gap);
		for (size_t k = 0; k < size; ++k)
			printf("%d ", array[k]);
		printf("\n");

		gap /= 3;
	}
}
