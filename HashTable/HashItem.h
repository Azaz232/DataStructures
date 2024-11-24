#pragma once
#include <string>
using namespace std;

struct HashItem
{
	string Key;
	string Value;
	HashItem* Previous;
	HashItem* Next;
};

