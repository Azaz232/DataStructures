#pragma once
#include "HashItem.h"
#include <string>

/// <summary>
/// Structure of the hash table
/// </summary>
struct HashTable
{
	/// <summary>
	/// Array of pointers
	/// </summary>
	HashItem** Items;

	/// <summary>
	/// Capacity of the hash table
	/// </summary>
	int Capacity;

	/// <summary>
	/// Current size of the hash table
	/// </summary>
	int Size;
};

/// <summary>
/// Growth factor of the hash table
/// </summary>
const int GrowthFactor = 2;

/// <summary>
/// Factor of the table being filled
/// </summary>
const double FillFactor = 0.75;

/// <summary>
/// Creates a sample of the structure
/// </summary>
/// <param name="capacity"> Capacity of the hash table </param>
/// <returns> a pointer to the hash table </returns>
HashTable* CreateHashTable(int capacity);

/// <summary>
/// Hash function
/// </summary>
/// <param name="key"> Key </param>
/// <param name="a"> Simple number for an array </param>
/// <param name="capacity"> Capacity of the array </param>
/// <returns> Index </returns>
int Pearson(const string& key, int a, int capacity);

/// <summary>
/// Inserts an element to the hash table
/// </summary>
/// <param name="hashTable"> A pointer to the hash table </param>
/// <param name="key"> A key of the element </param>
/// <param name="value"> Element's value </param>
void Insert(HashTable*& hashTable, const string& key, const string& value);

/// <summary>
/// Rehashes the hash table
/// </summary>
/// <param name="hashTable"> A pointer to the hash table </param>

//void Rehash(HashTable* hashTable);
HashTable* Rehash(HashTable* hashTable);

/// <summary>
/// Removes an element from the hash table
/// </summary>
/// <param name="hashTable"> A pointer to the hash table </param>
/// <param name="key"> A key at which to remove an element form </param>
void Remove(HashTable* hashTable, const string& key);

/// <summary>
/// Handles collisisons at the bucket
/// </summary>
/// <param name="table"> A pointer to the hash table </param>
/// <param name="hashCode"> Hash value for the key </param>
/// <param name="newItem"> A pointer to the new item of the table </param>
void HandleCollisisons(HashTable* table, int hashCode, HashItem* newItem);

/// <summary>
/// Searches a hash item by the key
/// </summary>
/// <param name="hashTable"> A pointer to the hash table </param>
/// <param name="key"> A key </param>
/// <returns> A pointer to the needed item </returns>
HashItem* Search(HashTable* hashTable, const string& key);

/// <summary>
/// Clears dynamicaly allocated space for the table
/// </summary>
void DeleteHashTable(HashTable* hashTable);
