#include "Dictionary.h"
#include "HashTable.h"
using namespace std;

Dictionary* CreateDictionary(int capacity)
{
	Dictionary* dictionary = new Dictionary;
	dictionary->HashTable = CreateHashTable(capacity);
	return dictionary;
}

void InsertToDictionary(Dictionary* dictionary, string& key, string& value)
{
	Insert(dictionary->HashTable, key, value);
}

void DeleteFromDictionary(Dictionary* dictionary, string& key)
{
	Remove(dictionary->HashTable, key);
}

 HashItem* SearchInDictionary(Dictionary* dictionary, string& key)
{
	 return Search(dictionary->HashTable, key);
}

 void DeleteDictionary(Dictionary* dictionary)
 {
	 DeleteHashTable(dictionary->HashTable);
	 delete dictionary;
 }

