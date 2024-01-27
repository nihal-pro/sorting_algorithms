#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int tmp;

    if (array == NULL || size <= 1)
        return;

    for (i = 0; i < size-1; i++)
    {
        for (j = i+1; j < size; j++)
        {
            if (array[j] < array[i])
            {
                tmp = array[j];
                array[j] = array[i];
                array[i] = tmp;
                print_array(array, size);
            }
        }
    }
}
