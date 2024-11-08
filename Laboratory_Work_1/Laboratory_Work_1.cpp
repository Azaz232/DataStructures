﻿#include <iostream>
#include "DynamicArray.h"
using namespace std;

//! \brief Resizes capacity of the array.
//! \param prompt A line.
int GetInput(const string& prompt)
{
    int value;
    cout << prompt;
    cin >> value;
    return value;
}

//! \brief Depending on index we either output an index or not.
//! \param index An index.
void PrintIndexResult(int index)
{
    if (index != -1)
    {
        cout << "Element found at index: " << index << endl;
    }
    else
    {
        cout << "Element not found. \n";
    }
}


int main()
{
    DynamicArray* array = CreateDynamicArray();

    while (true)
    {
        cout << "Current array \n";

        for (int i = 0; i < array->Size; i++)
        {
            cout << array->Array[i] << ", ";
        }
        cout << endl;

        cout << "Select the action you want to do: \n";
        cout << "1. Remove an element by index from an array \n";
        cout << "2. Remove an element by value from an array \n";
        cout << "3. Insert an element at the beginning \n";
        cout << "4. Insert an element at the end \n";
        cout << "5. Insert after a certain element \n";
        cout << "6. Sort array \n";
        cout << "7. Linear search for an element in an array \n";
        cout << "8. Binary search for an element in an array \n";

        int choice = GetInput("Your input: ");
        
        switch (choice)
        {
            case 1:
            {
                int index = GetInput("Enter the index to delete: \n");
                RemoveByIndex(array, index);
                break;
            }
            case 2:
            {
                int value = GetInput("Enter the value to delete: \n");
                RemoveByValue(array, value);
                break;
            }
            case 3:
            {
                int value = GetInput("Enter the element to insert it at the beginning: \n");
                AddElement(array, 0, value);
                break;
            }
            case 4:
            {
                int value = GetInput("Enter the element to inset it at the end: \n");
                AddElement(array, array->Size, value);
                cout << endl;
                break;
            }
            case 5:
            {
                int index = GetInput("Enter the index where you want to insert the value: \n");
                int value = GetInput("Enter the value you want to insert: \n");
                AddElement(array, index, value);
                break;
            }
            case 6:
            {
                SortArray(array);
                cout << "Array is sorted \n";
                break;
            }
            case 7:
            {
                int value = GetInput("Enter the value you want to find in the array: \n");
                int index = LinearSearch(array, value);

                PrintIndexResult(index);
                break;
            }
            case 8:
            {
                int value = GetInput("Enter the value you want to find in the array: \n");
                int index = BinarySearch(array, value);

                PrintIndexResult(index);
                break;
            }
            default:
                cout << "Unknown command. Try entering the command again \n";
        }
    }

    FreeArray(array);
}