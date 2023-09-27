#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
                size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Sort A subarray of integers.
 * @subarr: A Subarray of an Array of integers to sort.
 * @buff: A Buffer to Store The sorted subarray.
 * @front: The front index of the Array.
 * @mid: The middle index of the Array.
 * @back: The back index of the Array.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
                size_t back)
{
        size_t i, j, k = 0;

        printf("Merging...\n[left]: ");
        print_array(subarr + front, mid - front);

        printf("[right]: ");
        print_array(subarr + mid, back - mid);

        for (i = front, j = mid; i < mid && j < back; k++)
                buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
        for (; i < mid; i++)
                buff[k++] = subarr[i];
        for (; j < back; j++)
                buff[k++] = subarr[j];
        for (i = front, k = 0; i < back; i++)
                subarr[i] = buff[k++];

        printf("[Done]: ");
        print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Implement The Merge sort algorithm through Recursion.
 * @subarr: A subarray of an array of Integers to Sort.
 * @buff: A buffer to store The sorted Result.
 * @front: The front Index of The subarray.
 * @back: The back Index of The Subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
        size_t mid;

        if (back - front > 1)
        {
                mid = front + (back - front) / 2;
                merge_sort_recursive(subarr, buff, front, mid);
                merge_sort_recursive(subarr, buff, mid, back);
                merge_subarr(subarr, buff, front, mid, back);
        }
}

/**
 * merge_sort - Sort an Array Of integers In Ascending
 *              order Using The merge sort algorithm.
 * @array: An array Of Integers.
 * @size: The size Of the Array.
 *
 * Description: Implements The top-down merge Sort Algorithm.
 */
void merge_sort(int *array, size_t size)
{
        int *buff;

        if (array == NULL || size < 2)
                return;

        buff = malloc(sizeof(int) * size);
	if (buff == NULL)
                return;

        merge_sort_recursive(array, buff, 0, size);

        free(buff);
}
