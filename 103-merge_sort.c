#include "sort.h"

/**
 * merge - Merges two subarrays into a single sorted array.
 * @array: Pointer to the original array.
 * @left: Starting index of the left subarray.
 * @mid: Middle index (dividing point).
 * @right: Ending index of the right subarray.
 */
void merge(int *array, size_t left, size_t mid, size_t right)
{
	size_t i, j, k;
	size_t n1 = mid - left + 1;
	size_t n2 = right - mid;

	int *temp = malloc((n1 + n2) * sizeof(int));

	if (!temp)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	i = left;
	j = mid + 1;
	k = 0;

	while (i <= mid && j <= right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i <= mid)
		temp[k++] = array[i++];

	while (j <= right)
		temp[k++] = array[j++];

	for (size_t m = 0; m < k; ++m)
		array[left + m] = temp[m];
	free(temp);
}

/**
 * merge_sort - Recursively sorts an array using the merge sort
 * @array: Pointer to the array.
 * @left: Starting index of the subarray.
 * @right: Ending index of the subarray.
 */
void merge_sort(int *array, size_t left, size_t right)
{
	if (left < right)
	{
		size_t mid = left + (right - left) / 2;

		merge_sort(array, left, mid);
		merge_sort(array, mid + 1, right);
		merge(array, left, mid, right);
	}
}
