#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * insertion_sort_list - a function that sorts a doubly linked list of integers
 *                        in ascending order using the Insertion sort algorithm
 * @list: is a pointer to first node.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i = NULL, *_i = NULL, *_j = NULL;
	listint_t *sw = NULL;

	if (!list || !(*list)->next)
		return;
	i = (*list)->next;
	while (i)
	{
		_j = i->prev, _i = i;
		while (_j)
		{
			if (_j->n > _i->n)
			{
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
				sw = _i, _i = _j, _j = sw, print_list(*list);
			}
			_j = _j->prev, _i = _i->prev;
		}
		i = i->next;
	}
}
