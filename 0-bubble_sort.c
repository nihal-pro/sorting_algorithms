#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * bubble_sort - function that sorts an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, repeat = size;
	int tmp;

	if (array == NULL || size <= 1)
		return;

	while (repeat >= 1)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
			}
		}
		repeat--;
	}
}
