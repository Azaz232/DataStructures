#include "HashTable.h"
#include "HashItem.h"

HashTable* CreateHashTable(int capacity)
{
	HashTable* hashTable = new HashTable;
	hashTable->Capacity = capacity;
	hashTable->Size = 0;
	hashTable->Items = new HashItem * [hashTable->Capacity];

}