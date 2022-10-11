#include "sort.h"

/**
 * swap - swaps nodes next to each other
 * @list: pointer to the head node
 * @node: node to be swapped
 */
void swap(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev != NULL)
		node->prev->next = node->next;
	else
		(*list) = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}


/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: pointer to head node
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *sptr;
	bool swapped = true;

	if (!list || *list == NULL || (*list)->next == NULL)
		return;

	sptr = *list;
	while (swapped)
	{
		swapped = false;

		while (sptr->next != NULL)
		{
			if (sptr->n > sptr->next->n)
			{
				swap(list, sptr);
				swapped = true;
				print_list(*list);
			}
			else
				sptr = sptr->next;
		}
		if (!swapped)
			break;

		swapped = false;
		while (sptr->prev != NULL)
		{
			if (sptr->prev->n > sptr->n)
			{
				swap(list, sptr->prev);
				swapped = true;
				print_list(*list);
			}
			else
				sptr = sptr->prev;
		}
	}
}
