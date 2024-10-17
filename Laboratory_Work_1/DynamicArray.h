#pragma once
//TODO: remove
#include <iostream>
using namespace std;

//! \brief Struct of a dynamic array.
struct DynamicArray
{
	//! \brief Array's size.
	int Size;

	//! \brief Array's capacity.
	int Capacity;

	//! \brief Array.
	int* Array;
};

//TODO: RSDN
const int originalCapacity = 4;
//TODO: RSDN
const int growthFactor = 2;

// !\brief Creation of the array.
//TODO: return
DynamicArray* CreateDynamicArray();

//! \brief Resizes capacity of the array.
//! \param array Struct of the dynamic array.
void ResizeArray(DynamicArray* array, int capacity);

//! \brief Adds an element to the array.
//! \param array Struct of the dynamic array.
//! \param index Index of an element, where you want to add an element.
//! \param value Value of an element.
void AddElement(DynamicArray* array, int index, int value);	

//! \brief Deletes an element by an index.
//! \param array Struct of the dynamic array.
//! \param index Index of an element you want to delete.
void RemoveByIndex(DynamicArray* array, int index);

//! \brief Deletes a value of an element by value.
//! \param array Struct of the dynamic array.
//! \param value Value which we need to delete.
void RemoveByValue(DynamicArray* array, int value);

//! \brief Returns an element by its index.
//! \param array Struct of the dynamic array.
//! \param index Index by which we need to get the value.
//! \return Returns a value by the index.
int GetElement(DynamicArray* array, int index);

//! \brief Sorts the array.
//! \param array Struct of the dynamic array.
void SortArray(DynamicArray* array);

//! \brief Linear search for an element in an array.
//! \param array Struct of the dynamic array.
//! \param value Value whoose index needs to be found.
void LinearSearch(DynamicArray* array, int value);

//! \brief Binary search for an element in an array.
//! \param array Struct of the dynamic array.
//! \param value Value whose index needs to be found.
void BinarySearch(DynamicArray* array, int value);

//TODO: why const?
//! \brief Prints an array.
//! \param array Struct of the dynamic array.
void PrintArray(const DynamicArray* array);