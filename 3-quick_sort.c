#include "sort.h"

/**
 * partition - defines the pivot and swap the integers lower than the pivot.
 * @array: Pointer to the array.
 * @low: Lowest point of the array.
 * @high: Highest point of the array.
 * @size: Array's size.
 * Return: void.
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], temp = 0;
	int j;
	int i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * recursion_quick_sort - recursion that divides the array.
 * @array: Pointer to the array.
 * @low: Lowest point of the array.
 * @high: Highest point of the array.
 * @size: Array's size.
 * Return: void.
 */

void recursion_quick_sort(int *array, int low, int high, size_t size)
{
	int parti;

	if (low < high)
	{
		parti = partition(array, low, high, size);
		recursion_quick_sort(array, low, parti - 1, size);
		recursion_quick_sort(array, parti + 1, high, size);
	}
}

/**
 * quick_sort - that sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array
 * @size: size of the array
 * Return: nothing
 */

void quick_sort(int *array, size_t size)
{
	recursion_quick_sort(array, 0, size - 1, size);
}
