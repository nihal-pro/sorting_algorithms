#include "sort.h"

/**
 * Rec_heapfiy - recursive function that swap big number at beginning.
 * @ar: an array of integers.
 * @hp: the size of heap.
 * @i: index in array.
 * @size: size of an array of integers.
 */
void Rec_heapfiy(int *ar, size_t hp, size_t i, size_t size)
{
	size_t l = 2 * i + 1, r = 2 * i + 2, lr = i;
	int sw = 0;

	if (l < hp && ar[l] > ar[lr])
		lr = l;

	if (r < hp && ar[r] > ar[lr])
		lr = r;

	if (lr != i)
	{
		sw = ar[i], ar[i] = ar[lr], ar[lr] = sw;
		print_array(ar, size);
		Rec_heapfiy(ar, hp, lr, size);
	}
}

/**
 * heap_sort - a function that sorts an array of integers
 *      in ascending order using the Heap sort algorithm
 * @array: a pointer to an array.
 * @size: The size of an array.
 */
void heap_sort(int *array, size_t size)
{
	int i = size / 2 - 1;
	int sw;

	if (size <= 1)
		return;

	/*printf("i =  %d, size = %ld\n", i, size);*/
	while (i >= 0)
		Rec_heapfiy(array, size, i, size), i--;

	for (i = size - 1; i >= 0; i--)
	{
		sw = array[0], array[0] = array[i], array[i] = sw;

		if (i)
			print_array(array, size);
		Rec_heapfiy(array, i, 0, size);
	}
}
