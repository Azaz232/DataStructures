#include <iostream>
#include "List.h"
#include <chrono>
#include <limits>
#include <string>
#include <fstream> 

using namespace std;
using namespace std::chrono;

using namespace std;

/// <summary>
/// Indicated whether we found an element in the linked list or not.
/// </summary>
/// <param name="index"> Index from the function. </param>
void Found(int index)
{
    if (index == -1)
    {
        cout << "Element wasnt found in the linked list. \n";
    }
    else
    {
        cout << "Element was found at the index: " << index << endl;
    }
}

/// <summary>
/// Prompts for input and reads an integer value.
/// </summary>
/// <param name="prompt"> Prompt. </param>
/// <returns> Returns the integer value entered by the user. </returns>

int GetInput(const string& prompt)
{
    int value;
    string input;

    while (true)
    {
        cout << prompt;
        getline(cin, input);

        try
        {
            value = stoi(input);
            return value;
        }
        catch (const invalid_argument& e)
        {
            cout << "Invalid input. Enter an integer value.\n";
        }
        catch (const out_of_range& e)
        {
            cout << "Input is out of range. Enter a valid integer value.\n";
        }
    }
}

/// <summary>
/// For reaserch.
/// </summary>
/// <param name="listSize"> Size of the list.</param>
/// <param name="outputFile"> File. </param>
void measureInsertionAndDeletion(int listSize)
{
    List* doublyLinkedList = CreateLinkedList();

    auto startInsertBeginning = high_resolution_clock::now();
    for (int i = 0; i < listSize; ++i)
    {
        InsertAtBeginning(doublyLinkedList, i);
    }
    auto stopInsertBeginning = high_resolution_clock::now();
    auto durationInsertBeginning = duration_cast<microseconds>(stopInsertBeginning - startInsertBeginning);

    auto startInsertEnd = high_resolution_clock::now();
    for (int i = 0; i < listSize; ++i)
    {
        InsertAtEnd(doublyLinkedList, i);
    }
    auto stopInsertEnd = high_resolution_clock::now();
    auto durationInsertEnd = duration_cast<microseconds>(stopInsertEnd - startInsertEnd);

    long long durationDeleteBeginning = 0;
    if (doublyLinkedList->Size > 0) 
    {
        auto startDeleteBeginning = high_resolution_clock::now();
        Remove(doublyLinkedList, 0);
        auto stopDeleteBeginning = high_resolution_clock::now();
        durationDeleteBeginning = duration_cast<microseconds>(stopDeleteBeginning - startDeleteBeginning).count();
    }

    long long durationDeleteEnd = 0;
    if (doublyLinkedList->Size > 0) 
    {
        auto startDeleteEnd = high_resolution_clock::now();
        Remove(doublyLinkedList, doublyLinkedList->Size - 1);
        auto stopDeleteEnd = high_resolution_clock::now();
        durationDeleteEnd = duration_cast<microseconds>(stopDeleteEnd - startDeleteEnd).count();
    }

    cout << "List Size: " << listSize
        << ", Insertion at Beginning Time: " << durationInsertBeginning.count()
        << " microseconds, Insertion at End Time: " << durationInsertEnd.count()
        << " microseconds, Deletion from Beginning Time: " << durationDeleteBeginning
        << " microseconds, Deletion from End Time: " << durationDeleteEnd << " microseconds" << endl;

    FreeList(doublyLinkedList);
}

int main()
{
    List* doublyLinkedList = CreateLinkedList();

	while (true)
	{
        for (Node* node = doublyLinkedList->Head; node != nullptr; node = node->Next)
        {
            cout << node->Data << " ";
        }
        cout << endl;

        cout << "Select the action you want to do: \n";
        cout << "1. Insert an element at the beginning \n";
        cout << "2. Insert an element at the end \n";
        cout << "3. Insert element after a certain element \n";
        cout << "4. Insert element before a certain element \n";
        cout << "5. Remove an element by index from a list \n";
        cout << "6. Insert element at certain index \n";
        cout << "7. Linear search for an element in an list \n";
        cout << "8. Sort array \n";
        cout << "9. Measure time \n";

        int choice = GetInput("Your input: ");

        switch (choice)
        {
        case 1:
        {
            int value = GetInput("Enter an element you want to insert: \n");
            InsertAtBeginning(doublyLinkedList, value);
            break;
        }
        case 2:
        {
            int value = GetInput("Enter an element you want to insert: \n");
            InsertAtEnd(doublyLinkedList, value);
            break;
        }
        case 3:
        {
            int target = GetInput("Enter the value after which you want to insert the value: \n");
            int value = GetInput("Enter the value you want to insert: \n");
            InsertAfter(doublyLinkedList, target, value);
            break;
        }
        case 4:
        {
            int target = GetInput("Enter the value before which you want to insert an element: \n");
            int value = GetInput("Enter the value you want to insert: \n");
            InsertBefore(doublyLinkedList, target, value);
            break;
        }
        case 5:
        {
            int index = GetInput("Enter the index from which you want to delete an element: \n");
            Remove(doublyLinkedList, index);
            break;
        }
        case 6:
        {
            cout << doublyLinkedList->Size << endl;
            int index = GetInput("Enter the index at which you want to insert an element: \n");
            int value = GetInput("Enter the value you want to insert: \n");
            Insert(doublyLinkedList, index, value);
            break;
        }
        case 7:
        {
            int value = GetInput("Enter the value you want to find: \n");
            Found(LinearSearch(doublyLinkedList, value));
            break;
        }
        case 8:
        {
            Sort(doublyLinkedList);
            break;
        }
        case 9:
        {
            int value = GetInput("Size of the list you need to check duration: ");
            measureInsertionAndDeletion(value);
            break;
        }
        default:
        {
            cout << "Theres no such command \n";
            break;
        }
        }
	}

	FreeList(doublyLinkedList);
}