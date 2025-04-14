#include "sort.h"

void swap(int *x, int *y);
int partition(int *array, size_t size, int low, int high);
void quicksort_recursion(int *array, size_t size, int low, int high);
void quick_sort(int *array, size_t size);

/**
 * swap - swaps the value of two integers.
 * @x: pointer
 * @y: pointer
 */

void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * partition - order to subset of an array of ints using the
 * lomuto partition shceme with the last element as the pivot.
 * @array: array of ints
 * @size: size
 * @low: starting index of the given array
 * @high: ending index
 * Return: the final participation.
 */
int partition(int *array, size_t size, int low, int high)
{
	int *pivot_value, over, under;

	pivot_value = array + high;
	for (over = under = low; under < high; under++)
	{
		if (array[under] < *pivot_value)
		{
			if (over < under)
			{
				swap(array + under, array + over);
				print_array(array, size);
			}
			over++;
		}
	}

	if (array[over] > *pivot_value)
	{
		swap(array + over, pivot_value);
		print_array(array, size);
	}

	return (over);
}

/**
 * quicksort_recursion - implements the quicksort algorithm
 * through recursion
 * @array: array
 * @size: size
 * @low: starting index
 * @high: ending index
 */

void quicksort_recursion(int *array, size_t size, int low, int high)
{
	int part;

	if (high - low > 0)
	{
		part = partition(array, size, low, high);
		quicksort_recursion(array, size, low, part - 1);
		quicksort_recursion(array, size, part + 1, high);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending
 * order
 * @array: array of integers
 * @size: size of the given array.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursion(array, size, 0, size - 1);
}
