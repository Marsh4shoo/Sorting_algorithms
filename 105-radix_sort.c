#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - Get The maximum value in an Array of integers.
 * @array: An array of Integers.
 * @size: The size of The Array.
 *
 * Return: The maximum integer in The Array.
 */
int get_max(int *array, int size)
{
        int max, i;

        for (max = array[0], i = 1; i < size; i++)
        {
                if (array[i] > max)
                        max = array[i];
        }

        return (max);
}

/**
 * radix_counting_sort - Sort the significant digits Of an Array Of integers
 *                       in Ascending order Using The counting sort algorithm.
 * @array: An Array of Integers.
 * @size: The size of The Array.
 * @sig: The significant digit To Sort on.
 * @buff: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{

        int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        size_t i;

        for (i = 0; i < size; i++)
                count[(array[i] / sig) % 10] += 1;

        for (i = 0; i < 10; i++)
                count[i] += count[i - 1];

        for (i = size - 1; (int)i >= 0; i--)
        {
                buff[count[(array[i] / sig) % 10] - 1] = array[i];
                count[(array[i] / sig) % 10] -= 1;
        }

        for (i = 0; i < size; i++)
                array[i] = buff[i];
}

/**
 * radix_sort - Sort an Array of Integers in ascending
 *              Order using The radix sort algorithm.
 * @array: An array Of Integers.
 * @size: The size Of The Array.
 *
 * Description: Implements The LSD radix sort algorithm. Prints
 * the Array after each significant digit Increase.
 */
void radix_sort(int *array, size_t size)
{
        int max, sig, *buff;

        if (array == NULL || size < 2)
                return;

        buff = malloc(sizeof(int) * size);
        if (buff == NULL)
                return;
	 max = get_max(array, size);
        for (sig = 1; max / sig > 0; sig *= 10)
        {
                radix_counting_sort(array, size, sig, buff);
                print_array(array, size);
        }

        free(buff);
}
