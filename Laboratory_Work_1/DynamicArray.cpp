#include "DynamicArray.h"
#include <stdexcept>
using namespace std;

DynamicArray* CreateDynamicArray()
{
	DynamicArray* array = new DynamicArray;

	array->Size = 0;
	array->Capacity = OriginalCapacity;
	array->Array = new int[array->Capacity];

	return array;
}

void ResizeArray(DynamicArray* array, int capacity) 
{
	int* newArray = new int[capacity];
	for (int i = 0; i < array->Size; i++)
	{
		newArray[i] = array->Array[i];
	}
	delete[] array->Array;
	array->Array = newArray;
	array->Capacity = capacity;
}

void CheckRange(DynamicArray* array, int index)
{
	if (index < 0 || index > array->Size) 
	{
		throw out_of_range("Index out of range");
	}
}

void AddElement(DynamicArray* array, int index, int value)
{
	CheckRange(array, index);

	if (array->Size >= array->Capacity)
	{
		ResizeArray(array, array->Capacity*GrowthFactor);
	}

	for (int i = array->Size; i > index; --i)
	{
		array->Array[i] = array->Array[i - 1];
	}

	array->Array[index] = value;
	++array->Size;
}

void RemoveByIndex(DynamicArray* array, int index)
{
	CheckRange(array, index);

	for (int i = index; i < array->Size - 1; ++i)
	{
		array->Array[i] = array->Array[i + 1];
	}

	--array->Size;
	
	if (array->Size < array->Capacity / GrowthFactor && array->Capacity > OriginalCapacity)
	{
		ResizeArray(array, array->Capacity / GrowthFactor);
	}
}

void RemoveByValue(DynamicArray* array, int value)
{
	for (int i = 0; i < array->Size; ++i)
	{
		if (array->Array[i] == value)
		{
			RemoveByIndex(array, i);
			--i;
		}
	}
}


int GetElement(DynamicArray* array, int index)
{
	CheckRange(array, index);
	return array->Array[index];
}

//TODO: RSDN

//! \brief Swaps elements.
//! \param firstElement First element of the dynamic array.
//! \param secondElement First element of the dynamic array.
void Swap(int& firstElement, int& secondElement) 
{
	int temp = firstElement;
	firstElement = secondElement;
	secondElement = temp;
}
//TODO: RSDN

//! \brief Partitions an array around a pivot element.
//! \param array Pointer to the array to be partitioned.
//! \param low The starting index of the range to be partitioned.
//! \param high The ending index of the range to be partitioned.
//! \return The index of the pivot element after partitioning.
int Partition(int* array, int low, int high) 
{
	int pivot = array[high];
	int i = low - 1;

	for (int j = low; j < high; j++) 
	{
		if (array[j] < pivot) {
			i++;
			Swap(array[i], array[j]);
		}
	}

	Swap(array[i + 1], array[high]);
	return i + 1;
}

//TODO: RSDN

//! \brief Sorts an array using the QuickSort algorithm.
//! \param array Pointer to the array to be sorted.
//! \param low The starting index of the portion of the array to be sorted.
//! \param high The ending index of the portion of the array to be sorted.
void QuickSort(int* array, int low, int high) 
{
	if (low < high) 
	{
		int pivotIndex = Partition(array, low, high);
		QuickSort(array, low, pivotIndex - 1);
		QuickSort(array, pivotIndex + 1, high);
	}
}


void SortArray(DynamicArray* array)
{
	QuickSort(array->Array, 0, array->Size - 1);
}



int LinearSearch(DynamicArray* array, int value)
{
	for (int i = 0; i < array->Size; ++i)
	{
		if (array->Array[i] == value)
		{
			return i;
		}
	}
	return -1;
}

int BinarySearch(DynamicArray* array, int value)
{
	SortArray(array);
	int first = 0;
	int last = array->Size - 1;

	while (first <= last)
	{
		int middle = (first + last) / 2;
		if (array->Array[middle] == value)
		{
			return middle;
		}
		if (value < array->Array[middle])
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
	}
	return -1;
}

void FreeArray(DynamicArray* array)
{
	delete[] array->Array;
	delete array;
}