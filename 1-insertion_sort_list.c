#include "sort.h"

/**
 * swapNode - swaps node to arrange in a sorted way.
 * @left: pointer to current node.
 * @right: new node to swap with previous node.
 */ 
void swapNode(listint_t **h, listint_t **left, listint_t *right)
{
	(*left)->next = right->next;
	if (right->next != NULL)
		right->next->prev = *left;
	right->prev = (*left)->prev;
	right->next = *left;
	if ((*left)->prev != NULL)
		(*left)->prev->next = right;
	else
		*h = right;
	(*left)->prev = right;
	*left = right->prev;
}


/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to head node of doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur_t, *_prev, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	
	for (cur_t = (*list)->next; cur_t != NULL; cur_t = tmp)
	{
		tmp = cur_t->next;
		_prev = cur_t->prev;
		while (_prev != NULL && cur_t->n < _prev->n)
		{
			swapNode(list, &_prev, cur_t);
			print_list((const listint_t *)*list);
		}
	}
}
