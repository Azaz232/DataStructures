#pragma once
#include "HashItem.h"
#include <string>


/// \brief Structure representing a hash table
struct HashTable
{
    /// \brief Array of pointers to hash items
    HashItem** Items;

    /// \brief Capacity of the hash table
    int Capacity;

    /// \brief Current size of the hash table
    int Size;
};

/// \brief Growth factor of the hash table
const int GrowthFactor = 2;

/// \brief Factor of the table being filled
const double FillFactor = 0.75;

/// \brief Factor of the table being filled
const double MinFillFactor = 0.5;

/// \brief Creates a new hash table
/// \param capacity The capacity of the hash table
/// \return A pointer to the newly created hash table
HashTable* CreateHashTable(int capacity);

/// \brief Hash function using Pearson's method
/// \param key The key to hash
/// \param a A simple number for the array
/// \param capacity The capacity of the array
/// \return The index in the hash table
int HashFunction(const string& key, int a, int capacity);

/// \brief Finds the greatest common divisor (GCD) for two numbers
/// \param a The first number
/// \param b The second number
/// \return The greatest common divisor of the two numbers
int GreatestCommonDivisor(int a, int b);

/// \brief Finds a mutually simple number for the capacity of the table
/// \param capacity The capacity of the table
/// \return A mutually simple number for the given capacity
int MutuallySimpleNumber(int capacity);

/// \brief Inserts an element into the hash table
/// \param hashTable A pointer to the hash table
/// \param key The key of the element
/// \param value The value of the element
void Insert(HashTable*& hashTable, const string& key, const string& value);

/// \brief Rehashes the hash table
/// \param hashTable A pointer to the hash table
/// \param newCapacity New capacity of the table
/// \return A pointer to the rehashed hash table
HashTable* Rehash(HashTable* hashTable, int newCapacity);

/// \brief Removes an element from the hash table
/// \param hashTable A pointer to the hash table
/// \param key The key of the element to remove
void Remove(HashTable*& hashTable, const string& key);

/// \brief Handles collisions at the bucket
/// \param table A pointer to the hash table
/// \param hashCode The hash value for the key
/// \param newItem A pointer to the new item to insert
void HandleCollisions(HashTable* table, int hashCode, HashItem* newItem);

/// \brief Searches for a hash item by its key
/// \param hashTable A pointer to the hash table
/// \param key The key to search for
/// \return A pointer to the found hash item, or nullptr if not found
HashItem* Search(HashTable* hashTable, const string& key);

/// \brief Clears dynamically allocated space for the hash table
/// \param hashTable A pointer to the hash table to delete
void DeleteHashTable(HashTable* hashTable);
