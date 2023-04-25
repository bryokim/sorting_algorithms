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
 * bitonic_merge - Sort a bitonic sequence inside an array of integers.
 * @array: Pointer to an array of integers.
 * @size: Size of the array.
 * @start: Starting index of the sequence in array to sort.
 * @seq: Size of the sequence to sort.
 * @dir: The direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, char dir)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((dir == UP && array[i] > array[i + jump]) ||
			    (dir == DOWN && array[i] < array[i + jump]))
				swap(array, i, i + jump);
		}
		bitonic_merge(array, size, start, jump, dir);
		bitonic_merge(array, size, start + jump, jump, dir);
	}
}

/**
 * bitonic_seq - Convert an array of integers into a bitonic sequence.
 * @array: Pointer to an array of integers.
 * @size: Size of the array.
 * @start: Starting index of the sequence in array to sort.
 * @seq: Size of the sequence to sort.
 * @dir: The direction to sort in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char dir)
{
	size_t cut = seq / 2;
	char *str = (dir == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, dir);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending order using the
 * bitonic sort algorithm.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
