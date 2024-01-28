#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * calcul_pivot - get pivot(partition).
 * @array: an array of interger
 * @start: starting from.
 * @end: end of array.
 * @size: size of an array
 * Return: pivot index
 */
int calcul_pivot(int *array, int start, int end, size_t size)
{
	int pivot = array[end], i = start - 1, j, swp;

	for (j = start; j < end; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i < j)
			{
				swp = array[i];
				array[i] = array[j];
				array[j] = swp;
				print_array(array, size);
			}
		}
	}
	i++;
	if (array[i] > pivot)
	{
		swp = array[i];
		array[i] = array[end];
		array[end] = swp;
		print_array(array, size);
	}
	return (i);
}
/**
 * recursive - recursive function to stored array
 * @array: an array of integer.
 * @start: start of array.
 * @end: end of array
 * @size: size of an array.
 */
void recursive(int *array, int start, int end, size_t size)
{
	int pivot;

	if (start < end)
	{
		pivot = calcul_pivot(array, start, end, size);
		recursive(array, start, pivot - 1, size);
		recursive(array, pivot + 1, end, size);
	}
}
/**
 * quick_sort - function that sorts an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size <= 1)
		return;
	recursive(array, 0, size - 1, size);
}


