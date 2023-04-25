#include "sort.h"

/**
 * merge_subarr - Sort a subarray of integers.
 *
 * @arr: Subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @lo: First index of the array.
 * @mid: Middle index of the array.
 * @hi: Last index of the array.
 */
void merge_subarr(int *arr, int *buff, size_t lo, size_t mid, size_t hi)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(arr + lo, mid - lo);

	printf("[right]: ");
	print_array(arr + mid, hi - mid);

	for (i = lo, j = mid; i < mid && j < hi; k++)
		buff[k] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
	for (; i < mid; i++)
		buff[k++] = arr[i];
	for (; j < hi; j++)
		buff[k++] = arr[j];
	for (i = lo, k = 0; i < hi; i++)
		arr[i] = buff[k++];

	printf("[Done]: ");
	print_array(arr + lo, hi - lo);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 *
 * @arr: Subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @lo: First index of the subarray.
 * @hi: Last index of the subarray.
 */
void merge_sort_recursive(int *arr, int *buff, size_t lo, size_t hi)
{
	size_t mid;

	if (lo < hi - 1)
	{
		mid = lo + (hi - lo) / 2;
		merge_sort_recursive(arr, buff, lo, mid);
		merge_sort_recursive(arr, buff, mid, hi);
		merge_subarr(arr, buff, lo, mid, hi);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending order using the
 * merge sort algorithm.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
