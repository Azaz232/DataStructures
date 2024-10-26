#include <iostream>
#include "DynamicArray.h"
using namespace std;

//TODO: comment

//! \brief Resizes capacity of the array.
//! \param prompt Struct of the dynamic array.
int GetInput(const string& prompt)
{
    int value;
    cout << prompt;
    cin >> value;
    return value;
}

//! \brief Resizes capacity of the array.
//! \param prompt Struct of the dynamic array.
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
    //TODO: RSDN
    DynamicArray* Array = CreateDynamicArray();

    while (true)
    {
        cout << "Current array \n";
        //TODO: RSDN

        for (int i = 0; i < Array->Size; i++)
        {
            cout << Array->Array[i] << ", ";
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
                //TODO: insert to function remove duplication
                RemoveByIndex(Array, index);
                cout << endl;
                break;
            }
            case 2:
            {
                int value = GetInput("Enter the value to delete: \n");
                RemoveByValue(Array, value);
                cout << endl;
                break;
            }
            case 3:
            {
                int value = GetInput("Enter the element to insert it at the beginning: \n");
                AddElement(Array, 0, value);
                cout << endl;
                break;
            }
            case 4:
            {
                int value = GetInput("Enter the element to inset it at the end: \n");
                AddElement(Array, Array->Size, value);
                cout << endl;
                break;
            }
            case 5:
            {
                int index = GetInput("Enter the index where you want to insert the value: \n");
                int value = GetInput("Enter the value you want to insert: \n");
                AddElement(Array, index, value);
                cout << endl;
                break;
            }
            case 6:
            {
                SortArray(Array);
                cout << "Array is sorted \n";
                cout << endl;
                break;
            }
            case 7:
            {
                int value = GetInput("Enter the value you want to find in the array: \n");
                int index = LinearSearch(Array, value);

                PrintIndexResult(index);
                cout << endl;
                break;
            }
            case 8:
            {
                int value = GetInput("Enter the value you want to find in the array: \n");
                int index = BinarySearch(Array, value);

                PrintIndexResult(index);
                break;
            }
            case 0:
            {
                FreeArray(Array);
                return 0;
            }
            default:
                cout << "Unknown command. Try entering the command again \n";
        }
    }

    //TODO: to method
    /*delete[] Array->Array;
    delete Array;*/

}