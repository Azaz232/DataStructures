#include <iostream>
#include "Dictionary.h"
#include "HashTable.h"
#include "InputFunctions.h"

using namespace std;

/// \brief Prints the contents of the hash table
/// \param stack A pointer to the hash table
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
                cout << currentItem->Key << " - " << currentItem->Value 
                    << " | ";
                currentItem = currentItem->Next;
            }
        }
        cout << endl;
    }
}

/// \brief Prints the contents of the dictionary
/// \param stack A pointer to the dictionary
void PrintDictionary(Dictionary* dictionary)
{
    cout << "\tDictionary:\n";
    for (int i = 0; i < dictionary->HashTable->Capacity; i++)
    {
        HashItem* currentItem = dictionary->HashTable->Items[i];
        if (currentItem != nullptr)
        {
            cout << currentItem->Key << " : " << currentItem->Value
                << "\n";
        }
    }
    cout << endl;
}

int main()
{
    int dictionarySize = PositiveSize("Enter the size of the dictionary: ");
    Dictionary* dictionary = CreateDictionary(dictionarySize);

    while(true)
    {
        PrintHashTable(dictionary->HashTable);
        PrintDictionary(dictionary);
        cout << "\tSelect the action you want to do: \n";
        cout << "1. Insert \n";
        cout << "2. Delete \n";
        cout << "3. Search \n";
        cout << "q - Quit  \n\n";

        string choice = GetInputString("Enter your choice: ");

        if (choice == "q")
        {
            break;
        }
        if (IsNumber(choice))
        {
            int intChoice = stoi(choice);
            switch (intChoice)
            {
            case 1:
            {
                string key = GetInputString("Enter the key: ");
                string value = GetInputString("Enter the value to insert"
                    " to the hash table : ");
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
                if (SearchInDictionary(dictionary, key) != nullptr)
                {
                    HashItem* item = SearchInDictionary(dictionary, key);
                    cout << "For key '" << key << "', found value"
                        " is " << item->Value << endl;
                }
                else
                {
                    cout << "No value found for the key\n";
                }
                break;
            }
            default:
            {
                break;
            }
            }
        }
    }
    DeleteDictionary(dictionary);
}





