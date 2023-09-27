#include "sort.h"

/**
 * swap_ints - Swap two Integers in an Array.
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
 * bubble_sort - Sort an Array Of integers in Ascending Order.
 * @array: An Array Of integers to Sort.
 * @size: The size Of Array.
 *
 * Description: Prints the Array after each Swap.
 */
void bubble_sort(int *array, size_t size)
{
        size_t i, len = size;
        bool bubbly = false;

        if (array == NULL || size < 2)
                return;

        while (bubbly == false)
        {
                bubbly = true;
                for (i = 0; i < len - 1; i++)
                {
                        if (array[i] > array[i + 1])
                        {
                                swap_ints(array + i, array + i + 1);
                                print_array(array, size);
                                bubbly = false;
	                }
                }
                len--;
        }
}
