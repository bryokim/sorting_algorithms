#include "sort.h"

/**
 * swap_nodes - swap two nodes in a listint_t linked list.
 *
 * @head: Pointer to the adderess of the head of the list.
 * @node: First node to swap. Previous node to other.
 * @other: Second node to swap. Next node to node.
*/
void swap_nodes(listint_t **head, listint_t *node, listint_t *other)
{
	node->next = other->next;
	if (other->next)
		other->next->prev = node;
	other->next = node;
	other->prev = node->prev;
	if (node->prev)
		node->prev->next = other;
	else
		*head = other;
	node->prev = other;
	print_list(*head);
}

/**
 * cocktail_sort_list - sorts a list in ascending order using cocktail
 * shacker sort algorithm.
 *
 * @list: Pointer to the adderess of the head of the list to sort.
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *node, *tail;
	int swapped;

	if (!list || !*list)
		return;
	do {
		swapped = 0;
		node = *list;
		while (node)
		{
			if (!node->next)
				tail = node;
			if (node->next && node->n > node->next->n)
			{
				swap_nodes(list, node, node->next);
				swapped = 1;
			}
			else
			{
				node = node->next;
			}
		}
		if (!swapped)
			break;
		swapped = 0;
		node = tail;
		while (node)
		{
			if (node->prev && node->n < node->prev->n)
			{
				swap_nodes(list, node->prev, node);
				swapped = 1;
			}
			else
			{
				node = node->prev;
			}
		}
	} while (swapped);
}
