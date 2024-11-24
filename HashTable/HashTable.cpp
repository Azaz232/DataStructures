#include "HashTable.h"
#include "HashItem.h"

HashTable* CreateHashTable(int capacity)
{
	HashTable* hashTable = new HashTable;
	hashTable->Capacity = capacity;
	hashTable->Size = 0;
	hashTable->Items = new HashItem * [hashTable->Capacity];
	for (int i = 0; i < hashTable->Capacity; i++)
	{
		hashTable->Items[i] = nullptr;
	}
	return hashTable;
}

int Pearson(string& key, int a, int capacity)
{
	int hashValue = 0;
	int power = 1;
	for (char i : key)
	{
		hashValue += i * power;
		power *= a;
	}
	return abs(hashValue % capacity);
}

int GSD(int a, int b)
{
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int MutuallySimpleNumber(int capacity)
{
	int count = 1;
	for (int i = 1; i < capacity; i++)
	{
		if (GSD(i, capacity) == 1)
		{
			count = i;
		}
	}
	return count;
}

void Insert(HashTable* hashTable, string& key, string& value) 
{
	int hashValue = Pearson(key, MutuallySimpleNumber(hashTable->Capacity), hashTable->Capacity);
	HashItem* currentItem = hashTable->Items[hashValue];
	
	while (currentItem != nullptr)
	{
		if (currentItem->Key == key)
		{
			/*throw "u cannot add an item that already exists";*/
			return;
		}
	}
	HashItem* newItem = CreateHashItem();
	newItem->Key = key;
	newItem->Value = value;

	newItem->Next = hashTable->Items[hashValue];
	if (hashTable->Items[hashValue] != nullptr)
	{
		hashTable->Items[hashValue]->Previous = newItem;
	}
	hashTable->Items[hashValue] = newItem;
	hashTable->Size++;
}

void Rehash(HashTable* hashTable)
{
	int newCapacity = hashTable->Capacity * GrowthFactor;
	HashTable* newHashTable = CreateHashTable(newCapacity);
	
	for (int i = 0; i < hashTable->Capacity; i++)
	{
		HashItem* currentItem = hashTable->Items[i];
		while (currentItem != nullptr)
		{
			Insert(newHashTable, currentItem->Key, currentItem->Value);
			currentItem = currentItem->Next;
		}
	}
	DeleteHashTable(hashTable);
	hashTable = newHashTable;
}

void DeleteHashTable(HashTable* hashTable)
{
	if (hashTable == nullptr) {
		return;
	}
	for (int i = 0; i < hashTable->Capacity; i++) {
		HashItem* currentItem = hashTable->Items[i];
		while (currentItem != nullptr) {
			HashItem* temp = currentItem; 
			currentItem = currentItem->Next;
			delete temp;
		}
	}

	delete[] hashTable->Items;
	delete hashTable;
}

void Remove(HashTable* hashTable, string key)
{
	if (hashTable->Size == 0)
	{
		return;
	}
	int hashValue = Pearson(key, MutuallySimpleNumber(hashTable->Capacity), hashTable->Capacity);
	HashItem* currentItem = hashTable->Items[hashValue];
	while (currentItem != nullptr)
	{
		if (currentItem->Key == key)
		{
			if (currentItem->Previous != nullptr)
			{
				currentItem->Previous->Next = currentItem->Next;
			}
			else
			{
				hashTable->Items[hashValue] = currentItem->Next;
			}
			if (currentItem->Next != nullptr)
			{
				currentItem->Next->Previous = currentItem->Previous;
			}
		}
		delete currentItem;
		hashTable->Size--;
		return;
	}
	currentItem = currentItem->Next;
}
