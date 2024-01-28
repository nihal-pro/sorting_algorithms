#include "sort.h"

/**
 * count_sort - a function that count sort to the nth digit of the elements.
 * @array: a pointer to an array of integers.
 * @size: a size of an arrays.
 * @digit: return max number in list.
 */
void count_sort(int *array, size_t size, int digit)
{
	size_t i;
	int **buckets = NULL, j, a, _j;

	buckets = malloc(sizeof(int *) * 10);
	if (!buckets)
		return;
	for (i = 0; i < 10; i++)
	{
		buckets[i] = malloc(sizeof(int) * 100);
		if (!buckets[i])
			return;
		for (j = 0; j < 100; j++)
			buckets[i][j] = -1;
	}
	for (i = 0; i < size; i++)
	{
		for (_j = 0; _j < 100; _j++)
		{
			if (buckets[(array[i] / digit) % 10][_j] == -1)
			{
				buckets[(array[i] / digit) % 10][_j] = array[i];
				break; }
		}
	}
	i = 0;
	for (j = 0; j < 10; j++)
	{
		for (_j = 0; _j < 100; _j++)
		{
			if (i == size)
			{
				for (a = 0; a < 10; a++)
					free(buckets[a]);
				free(buckets);
				return;
			}
			if (buckets[j][_j] != -1)
				array[i] = buckets[j][_j], i++;
		}
	}
}
/**
 * get_max - a function that return maximum number in list.
 * @array: a pointer to an array of integers.
 * @size: a size of an arrays.
 * Return: return max number in list.
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max = 0;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * radix_sort - a function that sorts an array of integers in ascending
 *          order using the Radix sort algorithm.
 * @array: a pointer to an array of integers.
 * @size: a size of an arrays.
 */
void radix_sort(int *array, size_t size)
{
	int max = -1, digit;

	if (size < 2)
		return;

	max = get_max(array, size);
	/*printf("* Max = %d", max);*/

	for (digit = 1; max / digit > 0; digit *= 10)
		count_sort(array, size, digit), print_array(array, size);
}
