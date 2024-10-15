//#pragma once
#include "DynamicArray.h"
#include <iostream>
using namespace std;

DynamicArray* CreateDynamicArray()
{

	DynamicArray* array = new DynamicArray;

	array->Size = 0;
	array->Capacity = originalCapacity;
	array->Array = new int[array->Capacity];

	return array;
}

void IncreaseCapacity(DynamicArray* array) 
{
	array->Capacity *= growthFactor;
	int* newArray = new int[array->Capacity];
	for (int i = 0; i < array->Size; i++)
	{
		newArray[i] = array->Array[i];
	}
	delete[] array->Array;

	array->Array = newArray;
}


void DecreaseCapacity(DynamicArray* array) 
{
	array->Capacity /= growthFactor;
	int* newArray = new int[array->Capacity];
	for (int i = 0; i < array->Size; i++)
	{
		newArray[i] = array->Array[i];
	}
	delete[] array->Array;

	array->Array = newArray;
}

void CheckRange(DynamicArray* array, int index)
{
	if (index < 0 || index > array->Size) {
		cout << "Index out of range";
	}
}



void AddElement(DynamicArray* array, int index, int value)
{
	CheckRange(array, index);

	if (array->Size >= array->Capacity)
	{
		/*int newCapacity = array->Capacity * 2;
		int* newArray = new int[newCapacity];

		for (int i = 0; i < array->Size; i++)
		{
			newArray[i] = array->Array[i];
		}

		delete[] array->Array;

		array->Array = newArray;
		array->Capacity = newCapacity;*/

		IncreaseCapacity(array);

	}

	for (int i = array->Size; i > index; i--)
	{
		array->Array[i] = array->Array[i - 1];
	}

	array->Array[index] = value;
	array->Size++;
}

void RemoveByIndex(DynamicArray* array, int index)
{
	CheckRange(array, index);


	for (int i = index; i < array->Size - 1; i++)
	{
		array->Array[i] = array->Array[i + 1];
	}

	array->Size--;
	
	if (array->Size < array->Capacity / growthFactor)
	{
		/*int newCapacity = array->Capacity / 2;
		int* newArray = new int[newCapacity];

		for (int i = 0; i < array->Size; i++)
		{
			newArray[i] = array->Array[i];
		}
		delete[] array->Array;

		array->Array = newArray;
		array->Capacity = newCapacity;*/

		DecreaseCapacity(array);

	}
}

void RemoveByValue(DynamicArray* array, int value)
{
	int deleteIndex = -1;

	for (int i = 0; i < array->Size; i++)
	{
		if (array->Array[i] == value)
		{
			deleteIndex = i;
			break;
		}
	}

	if (deleteIndex != -1)
	{
		for (int i = deleteIndex; i < array->Size; i++)
		{
			array->Array[i] = array->Array[i + 1];
		}

		array->Size--;
	}
	else
	{
		cout << "Value wasn't found in the array" << endl;
	}
}


int GetElement(DynamicArray* array, int index)
{
	CheckRange(array, index);

	return array->Array[index];
}









void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int partition(int* arr, int low, int high) {
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j < high; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i + 1], arr[high]);
	return i + 1;
}


void quicksort(int* arr, int low, int high) {
	if (low < high) {
		int pivotIndex = partition(arr, low, high);
		quicksort(arr, low, pivotIndex - 1);
		quicksort(arr, pivotIndex + 1, high);
	}
}


void SortArray(DynamicArray* array)
{
	quicksort(array->Array, 0, array->Size - 1);
}







void LinearSearch(DynamicArray* array, int value)
{
	for (int i = 0; i < array->Size; i++)
	{
		if (array->Array[i] == value)
		{
			cout << "Requested value is placed at index: " << i << endl;
			return;
		}
	}
	cout << "Requested value wasn't found" << endl;
}

void BinarySearch(DynamicArray* array, int value)
{
	SortArray(array);
	int left = 0;
	int right = array->Size - 1;

	while (left <= right)
	{
		int middle = (left + right) / 2;

		if (array->Array[middle] == value)
		{
			cout << "Needed element is at the index: " << middle << endl;
			return;
		}
		else if (value < array->Array[middle])
		{
			right = middle - 1;
		}
		else
		{
			left = middle + 1;
		}
	}
	cout << "Element wasn't found in the array" << endl;
}

void PrintArray(const DynamicArray* array)
{
	cout << "Array elements: ";
	for (int i = 0; i < array->Size; i++)
	{
		cout << array->Array[i] << " ";
	}
	cout << endl;
}