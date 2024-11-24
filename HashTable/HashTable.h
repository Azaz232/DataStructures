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


