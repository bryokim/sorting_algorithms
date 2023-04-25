#include "sort.h"

/**
 * get_smallest_element_index - get the index of the smallest iteger in array.
 *
 * @array: Pointer to the array.
 * @start: Starting index.
 * @size: Size of the array.
 *
 * Return: Index of the smallest item.
*/
size_t get_smallest_element_index(int *array, size_t start, size_t size)
{
	size_t i, s;

	for (i = s = start; i < size; i++)
	{
		if (array[i] < array[s])
			s = i;
	}
	return (s);
}

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
 * selection_sort - sort an array in ascending order using selection
 * sort algorithm.
 *
 * @array: Pointer to the array to sort.
 * @size: Size of the array to sort.
*/
void selection_sort(int *array, size_t size)
{
	size_t i, s;

	for (i =  0; i < size; i++)
	{
		s = get_smallest_element_index(array, i, size);
		if (i != s)
		{
			swap(array, s, i);
			print_array(array, size);
		}
	}
}
