#include "sort.h"
/**
 * merge_sorted_array - a function that merge array.
 *          order using the Merge sort algorithm
 * @array: a pointer to an array of integers.
 * @l: a integer represent start of an array.
 * @m: a integer represent middle of an array.
 * @r: a integer represent end of an array.
 */
void merge_sorted_array(int *array, size_t l, size_t m, size_t r)
{
	size_t len_lft = m - l + 1, len_rt = r - m, i, j, k;
	int arr_lft[1000], arr_rt[1000];

	printf("Merging...\n");
	printf("[left]: ");
	for (i = 0; i < len_lft; i++)
		arr_lft[i] = array[l + i];
	print_array(arr_lft, i);
	printf("[right]: ");
	for (i = 0; i < len_rt; i++)
		arr_rt[i] = array[m + 1 + i];
	print_array(arr_rt, i);

	for (i = 0, j = 0, k = l; k <= r; k++)
	{
		if ((i < len_lft) && (j >= len_rt || arr_lft[i] <= arr_rt[j]))
			array[k] = arr_lft[i], i++;
		else
			array[k] = arr_rt[j], j++;
	}
	printf("[Done]: ");
	for (i = l; i <= r; i++)
	{
		if (i != l)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}
/**
 * split_recursion - a function that split array recursively
 * @array: a pointer to an array of integers.
 * @l: a integer represent start of an array.
 * @r: a integer represent end of an array.
 */
void split_recursion(int *array, size_t l, size_t r)
{
	int m;

	if (l >= r)
		return;

	m = (r + l - 1) / 2;
	split_recursion(array, l, m);
	split_recursion(array, m + 1, r);

	merge_sorted_array(array, l, m, r);
}
/**
 * merge_sort - a function that sorts an array of integers in ascending
 *          order using the Merge sort algorithm
 * @array: a pointer to an array of integers.
 * @size: a integer represent size of an array.
 */
void merge_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	split_recursion(array, 0, size - 1);
}
