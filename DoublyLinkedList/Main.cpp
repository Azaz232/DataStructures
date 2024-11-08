#include <iostream>
#include "List.h"

using namespace std;


int GetInput(const string& prompt)
{
    int value;
    cout << prompt;
    cin >> value;

    /*if (isdigit(value))
    {
        return value;
    }
    else
    {
        return -1;
    }*/
    return value;
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
        cout << "3. Insert after a certain element \n";
        /*cout << "4. Insert element after a certain element \n";
        cout << "5. Insert element before a certain element \n";
        cout << "6. Remove an element at the beginning \n";
        cout << "7. Remove an element at the end \n";
        cout << "8. Remove an element by index from an list \n";
        cout << "9. Remove an element by value from an list \n";
        cout << "10. Sort array \n";
        cout << "11. Linear search for an element in an list \n";*/

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
            int target = GetInput("Enter the value after which you want to insert the value: ");
            int value = GetInput("Enter the value you want to insert: ");
            InsertAfter(doublyLinkedList, target, value);
            break;
        }


        }


	}


	FreeList(doublyLinkedList);
}