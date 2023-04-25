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
 * bubble_sort - sort an array in ascending order usng the bubble sort
 * algorithm.
 *
 * @array: Pointer to array to sort.
 * @size: Size of the array.
*/
void bubble_sort(int *array, size_t size)
{
	size_t swapped, j, i;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;

		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array, j, j + 1);
				swapped = 1;
				print_array(array, size);
			}
		}
		if (!swapped)
			break;
	}
}
