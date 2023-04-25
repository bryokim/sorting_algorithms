#include <stdlib.h>

#include "sort.h"


#define LSD(A, i, x) ((A[i] / x) % 10)

/**
 * swap - swap two elements of an array at indices i and j.
 *
 * @array: Pointer to the array in which elements are swapped.
 * @i: Index of first element.
 * @j: Index of second element.
*/
void swap(int *array, size_t i, size_t j)
{
	int temp = array[i];

	array[i] = array[j];
	array[j] = temp;
}

/**
 * get_max - Get the largest number in an array.
 *
 * @array: Pointer to the array.
 * @size: Size of the array.
 *
 * Return: Largest number in array.
*/
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * radix_counting_sort - couting sort algorithm used in implementing the radix
 * sort.
 *
 * @array: Pointer to the array.
 * @size: Size of the array.
 * @div: Integer used in dividing elements in array to get different
 * arrays of digits at different positions.
*/
void radix_counting_sort(int *array, int size, int div)
{
	int count[10] = {0}, *output, i;

	for (i = 0; i < size; i++)
		count[LSD(array, i, div)] += 1;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	output = calloc(size, sizeof(int));
	if (!output)
		return;
	for (i = size - 1; i >= 0; i--)
	{
		count[LSD(array, i, div)] -= 1;
		output[count[LSD(array, i, div)]] = array[i];
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
}

/**
 * radix_sort - sort an integer array in ascending order using the
 * radix sort algorithm.
 *
 * @array: Pointer to the array.
 * @size: Size of the array.
*/
void radix_sort(int *array, size_t size)
{
	int max, i;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	for (i = 1; max / i > 0; i *= 10)
	{
		radix_counting_sort(array, size, i);
		print_array(array, size);
	}
}
