#pragma once
#include <string>
using namespace std;


/// \brief A structure representing a hash item
struct HashItem
{
    /// \brief A key associated with the hash item
    string Key;

    /// \brief The value of the hash item
    string Value;

    /// \brief A pointer to the previous hash item
    HashItem* Previous;

    /// \brief A pointer to the next hash item
    HashItem* Next;
};

/// \brief Creates a hash table item
/// \return A pointer to the newly created hash table item
HashItem* CreateHashItem();
