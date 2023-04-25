#include "sort.h"

#define LEFTCHILD(x) ((2 * x) + 1)

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
 * sift_down - move smallest numbers down the heap.
 *
 * @array: Pointer to the array.
 * @root: Index to consider as rot of heap.
 * @end: Last index of the array.
 * @size: Size of the array.
*/
void sift_down(int *array, size_t root, size_t end, size_t size)
{
	size_t temp, left_child;

	while (LEFTCHILD(root) <= end)
	{
		temp = root;
		left_child = LEFTCHILD(root);

		if (array[left_child] > array[temp])
			temp = left_child;
		if ((left_child + 1) <= end &&
		array[left_child + 1] > array[temp])
			temp = left_child + 1;

		if (temp == root)
			return;

		swap(array, temp, root);
		print_array(array, size);
		root = temp;
	}
}

/**
 * heapify - create a max heap.
 *
 * @array: Pointer to the array to operate on.
 * @size: Size of the array.
*/
void heapify(int *array, size_t size)
{
	int i = size - 1;

	while (i >= 0)
	{
		sift_down(array, i, size - 1, size);
		i--;
	}
}

/**
 * heap_sort - sort an array in ascending order using the heap
 * sort algorithm.
 *
 * @array: pointer to the array.
 * @size: Size of the array.
*/
void heap_sort(int *array, size_t size)
{
	size_t end = size - 1;

	if (!array || size < 2)
		return;

	heapify(array, size);

	while (end)
	{
		swap(array, end, 0);
		print_array(array, size);
		end--;
		sift_down(array, 0, end, size);
	}
}
