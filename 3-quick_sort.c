#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * lomuto_partition - Order a subset of an Array of integers According to
 *                    the lomuto Patition Scheme (last element as pivot).
 * @array: The array of Integers.
 * @size: The size of The Array.
 * @left: The starting index Of the subset to Order.
 * @right: The ending index Of The subset to Order.
 *
 * Return: The final partition Index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
        int *pivot, above, below;

        pivot = array + right;
        for (above = below = left; below < right; below++)
        {
                if (array[below] < *pivot)
                {
			if (above < below)
                        {
                                swap_ints(array + below, array + above);
                                print_array(array, size);
                        }
                        above++;
                }
        }

        if (array[above] > *pivot)
        {
                swap_ints(array + above, pivot);
                print_array(array, size);
        }

        return (above);
}

/**
 * lomuto_sort - Implement The quicksort algorithm through Recursion.
 * @array: An array Of Integers to Sort.
 * @size: The size of The Array.
 * @left: The starting index Of the Array partition to Order.
 * @right: The Ending index Of the Array partition to Order.
 *
 * Description: Uses Lomuto partition Scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	 int part;

        if (right - left > 0)
        {
                part = lomuto_partition(array, size, left, right);
                lomuto_sort(array, size, left, part - 1);
                lomuto_sort(array, size, part + 1, right);
        }
}

/**
 * quick_sort - Sort an Array Of integers In ascending
 *              order Using The quicksort algorithm.
 * @array: An array Of integers.
 * @size: The size Of Array.
 *
 * Description: Uses the Lomuto Partition Scheme. Prints
 *              the array after each swap Of two Elements.
 */
void quick_sort(int *array, size_t size)
{
        if (array == NULL || size < 2)
                return;

        lomuto_sort(array, size, 0, size - 1);
}
