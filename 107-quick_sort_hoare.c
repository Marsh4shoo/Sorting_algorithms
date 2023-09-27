#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

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
 * hoare_partition - Order a subset of an Array of Integers
 *                   According To the hoare partition Scheme.
 * @array: The array of Integers.
 * @size: The size of the Aarray.
 * @left: The Starting Index of the subset to Order.
 * @right: The Ending Index of the subset to Order.
 *
 * Return: The final Partition Index.
 *
 * Description: Uses the Last Element Of the Partition as the pivot.
 * Prints the Array after Each Swap Of two elements.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
        int pivot, above, below;

        pivot = array[right];
        for (above = left - 1, below = right + 1; above < below;)

		 {
                do {
                        above++;
                } while (array[above] < pivot);
                do {
                        below--;
                } while (array[below] > pivot);

                if (above < below)
                {
                        swap_ints(array + above, array + below);
                        print_array(array, size);
                }
        }

        return (above);
}

/**
 * hoare_sort - Implement The quicksort algorithm through recursion.
 * @array: An array of Integers to Sort.
 * @size: The size of the Aarray.
 * @left: The starting index of the array Partition to Order.
 * @right: The ending index of the array Partition to Order.
 *
 * Description: Uses the Hoare partition Scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
        int part;

        if (right - left > 0)
        {
                part = hoare_partition(array, size, left, right);
                hoare_sort(array, size, left, part - 1);
                hoare_sort(array, size, part, right);
        }
}

/**
 * quick_sort_hoare - Sort an Array of integers in ascending
 *                    Order using the quicksort algorithm.
 * @array: An Array of Integers.
 * @size: The size of the Array.
 *
 * Description: Uses the Hoare Partition scheme. Prints
 * The Array After each Swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
        if (array == NULL || size < 2)
                return;

        hoare_sort(array, size, 0, size - 1);
}

