#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * selection_sort - function that sorts an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void selection_sort(int *array, size_t size)
{
	size_t select, i, j;
	int tmp, count;

	if (array == NULL || size <= 1)
		return;
	for (i = 0; i < size; i++)
	{
		select = i;
		count = 0;
		for (j = i + 1; j < size; j++)
		{
			if (array[select] > array[j])
			{
				select = j;
				count++;
			}
		}
		tmp = array[i];
		array[i] = array[select];
		array[select] = tmp;
		if (count)
			print_array(array, size);
	}
}
