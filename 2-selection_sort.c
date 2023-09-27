#include "sort.h"

/**
 * swap_ints - Swap two integers in An Array.
 * @a: The first integer to Swap.
 * @b: The second integer to Swap.
 */
void swap_ints(int *a, int *b)
{
        int tmp;

        tmp = *a;
        *a = *b;
        *b = tmp;
}

/**
 * selection_sort - Sort an Array of integers in ascending Oder
 *                  using the Selection sort Algorithm.
 * @array: An array of Integers.
 * @size: The size of the Array.
 *
 * Description: Prints the Array after each Swap.
 */
void selection_sort(int *array, size_t size)
{
        int *min;
        size_t i, j;

        if (array == NULL || size < 2)
                return;

        for (i = 0; i < size - 1; i++)
        {
                min = array + i;
                for (j = i + 1; j < size; j++)
                        min = (array[j] < *min) ? (array + j) : min;

                if ((array + i) != min)
                {
			swap_ints(array + i, min);
                        print_array(array, size);
                }
        }
}
