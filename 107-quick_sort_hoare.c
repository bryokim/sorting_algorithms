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
 * hoare_partition - Order a subset of an array of integers
 * according to the hoare partition scheme.
 *
 * @array: Pointer to the array.
 * @lo: First index of array to start sorting at.
 * @hi: Last index of array to sort.
 * @size: Size of the array.
 *
 * Return: The final partition index.
 */
int hoare_partition(int *array, int lo, int hi, size_t size)
{
	int pivot, i, j;

	pivot = array[hi];
	for (i = lo - 1, j = hi + 1; i < j;)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);

		if (i < j)
		{
			swap(array, i, j);
			print_array(array, size);
		}
	}

	return (i);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 *
 * @array: Pointer to the array.
 * @lo: First index of array to start sorting at.
 * @hi: Last index of array to sort.
 * @size: Size of the array.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, int lo, int hi, size_t size)
{
	int p;

	if (hi > lo)
	{
		p = hoare_partition(array, lo, hi, size);
		hoare_sort(array, lo, p - 1, size);
		hoare_sort(array, p, hi, size);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers n ascending order using
 * quick sort. Hoare partition scheme is used.
 *
 * @array: Pointer to the array to sort.
 * @size: Size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, 0, size - 1, size);
}
