#include "HashTable.h"
#include "HashItem.h"

HashTable* CreateHashTable(int capacity)
{
	HashTable* hashTable = new HashTable;
	hashTable->Capacity = capacity;
	hashTable->Size = 0;
	hashTable->Items = new HashItem* [hashTable->Capacity];
	for (int i = 0; i < hashTable->Capacity; i++)
	{
		hashTable->Items[i] = nullptr;
	}
	return hashTable;
}

int HashFunction(const string& key, int a, int capacity)
{
	int hashCode = 0;
	int power = 1;
	for (char i : key)
	{
		hashCode += i * power;
		power *= a;
	}
	return abs(hashCode % capacity);
}

int GreatestCommonDivisor(int firstNumber, int secondNumber)
{
	while (secondNumber != 0) 
	{
		int temp = secondNumber;
		secondNumber = firstNumber % secondNumber;
		firstNumber = temp;
	}
	return firstNumber;
}

int MutuallySimpleNumber(int capacity)
{
	int count = 1;
	for (int i = 1; i < capacity; i++)
	{
		if (GreatestCommonDivisor(i, capacity) == 1)
		{
			count = i;
		}
	}
	return count;
}

void Insert(HashTable*& hashTable, const string& key, const string& value) 
{
	int hashCode = HashFunction(key, MutuallySimpleNumber(hashTable->Capacity),
		hashTable->Capacity);
	HashItem* currentItem = hashTable->Items[hashCode];
	
	while (currentItem != nullptr)
	{
		if (currentItem->Key == key && currentItem->Value == value) 
		{
			return;
		}
		currentItem = currentItem->Next;
	}
	HashItem* newItem = CreateHashItem();
	newItem->Key = key;
	newItem->Value = value;

	HandleCollisions(hashTable, hashCode, newItem);
	hashTable->Size++;

	double loadFactor = (double)hashTable->Size / (double)hashTable->Capacity;
	if (loadFactor >= FillFactor)
	{
		hashTable = Rehash(hashTable,  hashTable->Capacity * GrowthFactor);
	}
}

HashTable* Rehash(HashTable* hashTable, int newCapacity)
{
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
	return newHashTable;
}

void Remove(HashTable*& hashTable, const string& key)
{
	if (hashTable->Size == 0)
	{
		return;
	}

	int hashCode = HashFunction(key, MutuallySimpleNumber(hashTable->Capacity),
		hashTable->Capacity);
	HashItem* currentItem = hashTable->Items[hashCode];
	HashItem* previousItem = nullptr;

	while (currentItem != nullptr)
	{
		if (currentItem->Key == key)
		{
			if (previousItem != nullptr)
			{
				previousItem->Next = currentItem->Next;
			}
			else
			{
				hashTable->Items[hashCode] = currentItem->Next;
			}
			delete currentItem;
			hashTable->Size--;

			double loadFactor = (double)hashTable->Size / (double)hashTable->Capacity;
			if (loadFactor <= MinFillFactor)
			{
				hashTable = Rehash(hashTable, hashTable->Capacity / GrowthFactor);
			}
			return;
		}
		previousItem = currentItem;
		currentItem = currentItem->Next;
	}
}

void HandleCollisions(HashTable* table, int hashCode, HashItem* newItem)
{
	newItem->Next = table->Items[hashCode];
	table->Items[hashCode] = newItem;
}

HashItem* Search(HashTable* hashTable, const string& key)
{
	int hashCode = HashFunction(key, MutuallySimpleNumber(hashTable->Capacity),
		hashTable->Capacity);
	HashItem* currentItem = hashTable->Items[hashCode];
	while (currentItem != nullptr)
	{
		if (currentItem->Key == key)
		{
			return currentItem;
		}
		currentItem = currentItem->Next;
	}
	return nullptr;
}

void DeleteHashTable(HashTable* hashTable)
{
	if (hashTable == nullptr)
	{
		return;
	}
	for (int i = 0; i < hashTable->Capacity; i++)
	{
		HashItem* currentItem = hashTable->Items[i];
		while (currentItem != nullptr)
		{
			HashItem* temp = currentItem; 
			currentItem = currentItem->Next;
			delete temp;
		}
	}
	delete[] hashTable->Items;
	delete hashTable;
}
