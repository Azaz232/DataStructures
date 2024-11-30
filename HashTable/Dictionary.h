#pragma once
#include "HashTable.h"

/// <summary>
/// Structure of the dictionary
/// </summary>
struct Dictionary
{
	/// <summary>
	/// A pointer to the hash table
	/// </summary>
	HashTable* HashTable;
};

/// <summary>
/// Creates a sample of the dictionary
/// </summary>
/// <param name="capacity"> Capacity of the dictionary </param>
/// <returns> A pointer to the dictionary </returns>
Dictionary* CreateDictionary(int capacity);

/// <summary>
/// Inserts value to the dictionary
/// </summary>
/// <param name="dictionary"> A pointer to the dictionary </param>
/// <param name="key"> A key </param>
/// <param name="value"> A value to insert </param>
void InsertToDictionary(Dictionary* dictionary, string& key, string& value);

/// <summary>
/// Deletes value from the dictionary
/// </summary>
void DeleteFromDictionary(Dictionary* dictionary, string& key);

/// <summary>
/// Searches value by key
/// </summary>
/// <param name="dictionary"> A pointer to the dictionary </param>
/// <param name="key"> A key </param>
/// <returns> A pointer to the item </returns>
HashItem* SearchInDictionary(Dictionary* dictionary, string& key);

/// <summary>
/// Clears dynamically allocated memory 
/// </summary>
void DeleteDictionary(Dictionary* dictionary);
