#pragma once
#include "HashTable.h"

/// \brief Structure representing a dictionary
struct Dictionary
{
    /// \brief A pointer to the hash table
    HashTable* HashTable;
};

/// \brief Creates a new dictionary
/// \param capacity The capacity of the dictionary
/// \return A pointer to the newly created dictionary
Dictionary* CreateDictionary(int capacity);

/// \brief Inserts a value into the dictionary
/// \param dictionary A pointer to the dictionary
/// \param key The key to insert
/// \param value The value to insert
void InsertToDictionary(Dictionary* dictionary, const std::string& key, const std::string& value);

/// \brief Deletes a value from the dictionary
/// \param dictionary A pointer to the dictionary
/// \param key The key of the value to delete
void DeleteFromDictionary(Dictionary* dictionary, const std::string& key);

/// \brief Searches for a value by key in the dictionary
/// \param dictionary A pointer to the dictionary
/// \param key The key to search for
/// \return A pointer to the found item, or nullptr if not found
HashItem* SearchInDictionary(Dictionary* dictionary, const std::string& key);

/// \brief Clears dynamically allocated memory for the dictionary
/// \param dictionary A pointer to the dictionary to delete
void DeleteDictionary(Dictionary* dictionary);
