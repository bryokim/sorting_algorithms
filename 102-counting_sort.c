#include <stdlib.h>
#include "sort.h"

/**
 * get_largest_num - Get the largest number in an array of integers.
 *
 * @array: Pointer to the array.
 * @size: Size of the array.
 *
 * Return: Largest number in array.
*/
size_t get_largest_num(int *array, size_t size)
{
	size_t i;
	int largest = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > largest)
			largest = array[i];
	}
	return (largest);
}

/**
 * counting_sort - Sort an array of integers in ascending order using the
 * counting sort algorithm.
 *
 * @array: Pointer to the array.
 * @size: Size of the array.
*/
void counting_sort(int *array, size_t size)
{
	size_t k, i;
	int *count, *output;

	if (!array || size < 2)
		return;

	k = get_largest_num(array, size);
	count = calloc(k + 1, sizeof(int));
	if (!count)
		return;

	for (i = 0; i < size; i++)
		count[array[i]] += 1;

	for (i = 1; i <= k; i++)
		count[i] += count[i - 1];

	print_array(count, k + 1);
	output = calloc(size, sizeof(int));
	if (!output)
	{
		free(count);
		return;
	}

	for (i = 0; i < size; i++)
	{
		count[array[i]] -= 1;
		output[count[array[i]]] = array[i];
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
