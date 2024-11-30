#include <iostream>
#include "Dictionary.h"
#include "HashTable.h"

using namespace std;

/// <summary>
/// Checks whether the string is a number
/// </summary>
/// <param name="prompt"> Prompt </param>
/// <returns> True if the string is a number </returns>
bool isNumber(const string& msg)
{
    if (msg.empty())
    {
        return false;
    }
    size_t start = 0;
    if (msg[0] == '-' || msg[0] == '+')
    {
        start = 1;
    }
    for (size_t i = start; i < msg.size(); ++i)
    {
        if (!isdigit(msg[i]))
        {
            return false;
        }
    }
    return true;
}

/// <summary>
/// Getsinput from the user
/// </summary>
/// <param name="prompt"> Prompt </param>
/// <returns> Number </returns>
int GetInput(const string& msg)
{
    string input;
    cout << msg;
    cin >> input;
    if (isNumber(input))
    {
        return stoi(input);
    }
    else
    {
        cout << "Unknown command. Try entering the command again." << endl;
        return GetInput(msg);
    }
}

int PositiveSize(const string& msg)
{
    string input;
    cout << msg;
    cin >> input;

    if (!isNumber(input) || stoi(input) <= 0)
    {
        cout << endl;
        cout << "Size must be positive or not be zero." << endl;
        cout << endl;
        return PositiveSize(msg);
    }
    else
    {
        return stoi(input);
    }
}


string GetInputString(const string& msg)
{
    string input;
    cout << msg;
    cin >> input;
    return input;
}

void PrintHashTable(HashTable* hashTable)
{
    cout << "\tHash Table:\n";
    for (int i = 0; i < hashTable->Capacity; i++)
    {
        cout << i + 1 << " ) ";
        if (hashTable->Items[i])
        {
            HashItem* currentItem = hashTable->Items[i];
            while (currentItem)
            {
                cout << currentItem->Key << " - " << currentItem->Value << " | ";
                currentItem = currentItem->Next;
            }
        }
        cout << endl;
    }
}

int main()
{
    int dictionarySize = PositiveSize("Enter the size of the dictionary: ");
    Dictionary* dictionary = CreateDictionary(dictionarySize);

    while(true)
    {
        PrintHashTable(dictionary->HashTable);
        cout << "\tSelect the action you want to do: \n";
        cout << "1. insert a value \n";
        cout << "2. delete value \n";
        cout << "3. search \n";
        cout << "4. Exit loop \n";

        int choice = GetInput("Enter your choice: ");

        switch(choice)
        {
        case 1:
        {
            string key = GetInputString("Enter the key: ");
            string value = GetInputString("Enter the value to insert to the hash table: ");
            InsertToDictionary(dictionary, key, value);
            break;
        }
        case 2:
        {
            string key = GetInputString("Enter the key: ");
            DeleteFromDictionary(dictionary, key);
            break;
        }
        case 3:
        {
            string key = GetInputString("Enter the key: ");
            HashItem* item = SearchInDictionary(dictionary, key);
            cout << "for key " << key << " found " << item->Value << endl;
            break;
        }
        case 4:
        {
            DeleteDictionary(dictionary);
            break;
        }
        default:
        {
            break;
        }
        }
    }
    DeleteDictionary(dictionary);
}





