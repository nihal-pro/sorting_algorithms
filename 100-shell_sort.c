#include "sort.h"

/**
 * shell_sort - a function that sorts an array of integers
 *  in ascending order using the Shell sort algorithm, using the Knuth sequence
 * @array: a pointer to an array of integers
 * @size: The size of an array.
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, g = 1;
	int sw;

	if (size < 2)
		return;

	/*generate the knuth sequence 1 4 13 40 121 ... */
	while (g < (size - 1) / 3) /*equale to g < size and divide after that by 3*/
		g = 3 * g + 1;
	/*printf("- %ld\n", g);*/

	/*the last gap is 1*/
	while (g >= 1)
	{
		for (i = g; i < size; i++)
		{
			/* sw take value at idx i, to swap*/
			sw = array[i];
			for (j = i; j >= g && sw <= array[j - g]; j -= g)
			{
				/*if value sw last than array i - g than take value*/
				array[j] = array[j - g];
			}
			/*array of j take smaller number in list*/
			array[j] = sw;
		}
		print_array(array, size);
		/*printf("- %ld\n", g);*/
		g /= 3; /* equale to g = g * 3 - 1*/
	}
}
