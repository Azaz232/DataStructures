#pragma once
#include <string>
using namespace std;

/// <summary>
/// A structure of the hash item
/// </summary>
struct HashItem
{
	/// <summary>
	/// A key
	/// </summary>
	string Key;

	/// <summary>
	/// A value of the item
	/// </summary>
	string Value;

	/// <summary>
	/// A pointer to the previous item
	/// </summary>
	HashItem* Previous;

	/// <summary>
	/// A pointer to the next pointer
	/// </summary>
	HashItem* Next;
};

/// <summary>
/// Creates a hash table item
/// </summary>
/// <returns> A poiter to the hash table item </returns>
HashItem* CreateHashItem();
