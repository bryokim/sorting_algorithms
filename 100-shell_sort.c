#include "sort.h"

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
 * shell_sort - Sorts an array of integers in ascending order
 * using the shell sort algorithm. Knuth sequence is used.
 *
 * @array: Pointer to the array.
 * @size: Size of the array.
*/
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (!array || size < 2)
		return;

	gap = 1;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		gap = (gap - 1) / 3;

		print_array(array, size);
	}
}
