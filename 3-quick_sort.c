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
 * quick_sort_helper - implements quick sort algorithm using
 * Lomuto partition scheme.
 *
 * @array: Pointer to the array.
 * @lo: Starting index.
 * @hi: Ending index.
 * @size: Size of the array.
*/
void quick_sort_helper(int *array, int lo, int hi, size_t size)
{
	int i, j, pivot;

	if (lo >= hi || lo < 0)
		return;

	pivot = array[hi];
	i = lo - 1;
	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(array, i, j);
				print_array(array, size);
			}
		}
	}
	i++;
	if (i != hi)
	{
		swap(array, i, hi);
		print_array(array, size);
	}
	quick_sort_helper(array, lo, i - 1, size);
	quick_sort_helper(array, i + 1, hi, size);
}

/**
 * quick_sort - Sorts an array in ascending order using quick sort
 * algorithm.
 *
 * @array: Pointer to the array to sort.
 * @size: Size of the array.
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}
