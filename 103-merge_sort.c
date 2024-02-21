#include "sort.h"

/**
 * compare_merge - compare then megrge two arrays
 * @array: array of integers
 * @start: start index
 * @stop: stop index
 * @new: result
 */
void compare_merge(int *array, size_t start, size_t stop, int *new)
{
	size_t i = start, j, k, mid;

	j = mid = (start + stop) / 2;
	printf("Merging...\n");
	printf("[lef]}: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, stop - mid);

	for (k = start; k < stop; k++)
	{
		if ((i < mid && j >= stop) || array[i] <= array[j])
			new[k] = array[i++];
		else
			new[k] = array[j++];
	}
	printf("[Done]: ");
	print_array(new + start, stop - start);
}

/**
 * sort_top_down - sort recursively
 * @array: array of integers to sort
 * @start: start index
 * @stop: stop index
 * @new: sorted array
 */
void sort_top_down(int *array, size_t start, size_t stop, int *new)
{
	size_t mid;

	if (stop - start < 2)
		return;
	mid = (start + stop) / 2;
	sort_top_down(new, start, mid, array);
	sort_top_down(new, mid, stop, array);
	compare_merge(array, start, stop, new);
}

/**
 * merge_sort - implements merge sort
 * @array: array of integers to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;
	size_t i;

	if (!array || size < 2)
		return;
	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;
	for (i = 0; i < size; i++)
		temp[i] = array[i];
	sort_top_down(temp, 0, size, array);
	free(temp);
}
