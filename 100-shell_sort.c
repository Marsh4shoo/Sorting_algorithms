#include "sort.h"

/**
 * swap_ints - Swap two Integers in An Array.
 * @a: The first integer To Swap.
 * @b: The second integer To Swap.
 */
void swap_ints(int *a, int *b)
{
        int tmp;

        tmp = *a;
        *a = *b;
        *b = tmp;
}

/**
 * shell_sort - Sort an Array Of integers in Ascending
 *              order Using The shell sort algorithm.
 * @array: An array Of Integers.
 * @size: The size of The Array.
 *
 * Description: Uses the Knuth Interval Sequence.
 */
void shell_sort(int *array, size_t size)
{
        size_t gap, i, j;

        if (array == NULL || size < 2)
                return;

        for (gap = 1; gap < (size / 3);)
                gap = gap * 3 + 1;

        for (; gap >= 1; gap /= 3)
        {
                for (i = gap; i < size; i++)
                {
                        j = i;
                        while (j >= gap && array[j - gap] > array[j])
                        {
				 swap_ints(array + j, array + (j - gap));
                                j -= gap;
                        }
                }
                print_array(array, size);
        }
}
