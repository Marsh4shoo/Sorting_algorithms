/*
 * File: 106-bitonic_sort.c
 * Auth: Marshal Zvinoira
 */

#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
                char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

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
 * bitonic_merge - Sort A Bitonic sequence inside an Array of Integers.
 * @array: An array of Integers.
 * @size: The size of the Array.
 * @start: The starting index of the Sequence in Array to sort.
 * @seq: The size of the Sequence To Sort.
 * @flow: The Direction to Sort in.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
                char flow)
{
        size_t i, jump = seq / 2;

	 if (seq > 1)
        {
                for (i = start; i < start + jump; i++)
                {
                        if ((flow == UP && array[i] > array[i + jump]) ||
                            (flow == DOWN && array[i] < array[i + jump]))
                                swap_ints(array + i, array + i + jump);
                }
                bitonic_merge(array, size, start, jump, flow);
                bitonic_merge(array, size, start + jump, jump, flow);
        }
}

/**
 * bitonic_seq - Convert an Array of integers into a bitonic Sequence.
 * @array: An Array of Integers.
 * @size: The Size of The Array.
 * @start: The Starting Index of A block of The Building bitonic sequence.
 * @seq: The size of a block of The building bitonic sequence.
 * @flow: The direction to Sort The bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
        size_t cut = seq / 2;
        char *str = (flow == UP) ? "UP" : "DOWN";

	 if (seq > 1)
        {
                printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
                print_array(array + start, seq);

                bitonic_seq(array, size, start, cut, UP);
                bitonic_seq(array, size, start + cut, cut, DOWN);
                bitonic_merge(array, size, start, seq, flow);

                printf("Result [%lu/%lu] (%s):\n", seq, size, str);
                print_array(array + start, seq);
        }
}

/**
 * bitonic_sort - Sort an Array Of integers In ascending
 *                Order using The bitonic sort algorithm.
 * @array: An Array of Integers.
 * @size: The size of the Array.
 *
 * Description: Prints the array After Each Swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
        if (array == NULL || size < 2)
                return;

        bitonic_seq(array, size, 0, size, UP);
}
