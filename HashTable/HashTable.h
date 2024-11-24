#pragma once
#include "HashItem.h"
#include <string>

struct HashTable
{
	HashItem** Items;
	int Capacity;
	int Size;
};

const int GrowthFactor = 2;

const double FillFactor = 0.75;

HashTable* CreateHashTable(int capacity);

/// <summary>
/// Hash function
/// </summary>
/// <param name="key"> Key </param>
/// <param name="a"> Simple number for an array </param>
/// <param name="capacity"> Capacity of the array </param>
/// <returns> Index </returns>
int Pearson(string& key, int a, int capacity);









