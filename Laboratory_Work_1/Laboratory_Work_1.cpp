﻿#include <iostream>
#include "DynamicArray.h"
using namespace std;

int GetInput(const string& prompt)
{
    int value;
    cout << prompt;
    cin >> value;
    return value;
}

int main()
{
    DynamicArray* Array = CreateDynamicArray();


    cout << "Current array\n";
    for (int i = 0; i < Array->Size; i++) {
        cout << Array->Array[i] << ", ";
    }
    cout << endl;



    int choice;
    while (true)
    {
        cout << "Select the action you want to do: " << endl;
        cout << "1. Remove an element by index from an array" << endl;
        cout << "2. Remove an element by value from an array" << endl;
        cout << "3. Insert an element at the beginning" << endl;
        cout << "4. Insert an element at the end" << endl;
        cout << "5. Insert after a certain element" << endl;
        cout << "6. Sort array" << endl;
        cout << "7. Linear search for an element in an array" << endl;
        cout << "8. Binary search for an element in an array" << endl;
        cout << "Your input: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int index = GetInput("Enter the index to delete: ");
            RemoveByIndex(Array, index);
            PrintArray(Array);
            cout << endl;
            break;
        }
        case 2:
        {
            int value = GetInput("Enter the value to delete: ");
            RemoveByValue(Array, value);
            PrintArray(Array);
            cout << endl;
            break;
        }
        case 3:
        {
            int value = GetInput("Enter the element to insert it at the beginning: ");
            AddElement(Array, 0, value);
            PrintArray(Array);
            cout << endl;
            break;
        }
        case 4:
        {
            int value = GetInput("Enter the element to inset it at the end: ");
            AddElement(Array, Array->Size, value);
            PrintArray(Array);
            cout << endl;
            break;
        }
        case 5:
        {
            int index = GetInput("Enter the index where you want to insert the value: ");
            int value = GetInput("Enter the value you want to insert: ");
            AddElement(Array, index, value);
            PrintArray(Array);
            cout << endl;
            break;
        }
        case 6:
        {
            SortArray(Array);
            cout << "Array is sorted " << endl;
            PrintArray(Array);
            cout << endl;
            break;
        }
        case 7:
        {
            int value = GetInput("Enter the value you want to find in the array: ");
            LinearSearch(Array, value);
            PrintArray(Array);
            cout << endl;
            break;
        }
        case 8:
        {
            int value = GetInput("Enter the value you want to find in the array: ");
            BinarySearch(Array, value);
            PrintArray(Array);
            cout << endl;
            break;
        }
        default:
            cout << "Unknown command. Try entering the command again";
        }
    }


    delete[] Array->Array;
    delete Array;

}