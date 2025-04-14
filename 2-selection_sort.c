#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: array
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 1, temp = 0, min_pos = 0, length = size - 1;

	if (size < 2)
		return;

	while (i < length)
	{
		if (j == size)
		{
			if (i != min_pos)
			{
				temp = array[i];
				array[i] = array[min_pos];
				array[min_pos] = temp;
				print_array(array, size);
			}
			++i;
			min_pos = i;
			j = i + 1;
			continue;
		}
		if (array[min_pos] > array[j])
			min_pos = j;

		++j;
	}
}
