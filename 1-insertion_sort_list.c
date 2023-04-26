#include "sort.h"

/**
 * insertion_sort_list - sort a doubly linked list in ascending order
 * using the insertion sort algorithm.
 *
 * @list: Pointer to the address of the head of the list.
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *prev_node, *next_node;

	if (!list || !*list || !(*list)->next)
		return;

	for (node = (*list)->next; node; node = next_node)
	{
		next_node = node->next;
		prev_node = node->prev;

		while (prev_node && prev_node->n > node->n)
		{
			prev_node->next = node->next;
			if (node->next)
				node->next->prev = prev_node;
			node->next = prev_node;
			node->prev = prev_node->prev;
			if (prev_node->prev)
				prev_node->prev->next = node;
			else
				(*list) = node;
			prev_node->prev = node;

			print_list(*list);
			prev_node = node->prev;
		}
	}
}
