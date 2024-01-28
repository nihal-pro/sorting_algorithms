#include "sort.h"

/**
 * swap - swap to node
 * @list: a pointer to first node.
 * @_i: a pointer to node.
 * @_j: a pointer to node.
 */
void swap(listint_t **list, listint_t *_i, listint_t *_j)
{
	listint_t *sw = NULL;

	if (!_j->prev)
	{
		*list = (*list)->next, (*list)->prev = NULL;
		if (_i->next)
		{
			_i = _i->next, _i->prev = _j, _j->next = _i;
			_j->prev = *list, (*list)->next = _j, _i = *list;
		}
		else
			_i->next = _j, _j->prev = _i, _j->next = NULL;
	}
	else if (_j->prev && _i->next)
	{
		sw = _j->prev, _j->next = _i->next, _j->next->prev = _j;
		_i->next = _j, _j->prev = _i, _i->prev = sw, sw->next = _i;
	}
	else
	{
		sw = _j->prev, sw->next = _i, _i->prev = sw;
		_i->next = _j, _j->prev = _i, _j->next = NULL;
	}
	print_list(*list);
}

/**
 * cocktail_sort_list - a function that sorts a doubly linked list of integers
 *          inascending order using the Cocktail shaker sort algorithm
 * @list: a pointer to double linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *i = NULL, *_i = NULL;
	int swapped = 1;

	if (!list || !(*list)->next)
		return;

	while (swapped)
	{
		swapped = 0;
		for (i = (*list)->next; i; i = i->next)
		{
			_i = i->prev;
			if (_i->n > i->n)
				swapped = 1, swap(&*list, i, _i);
			if (!i->next)
				break;
		}
		if (!swapped)
			return;

		swapped = 0;
		i = i->prev;
		/* printf("%d\n", i->n);*/
		while (i)
		{
			_i = i->next;
			if (i->n > _i->n)
				swapped = 1, swap(&*list, _i, i);
			i = i->prev;
		}
	}
}
