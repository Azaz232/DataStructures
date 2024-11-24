#include "HashItem.h"

HashItem* CreateHashItem()
{
	HashItem* hashItem = new HashItem;
	hashItem->Next = nullptr;
	hashItem->Previous = nullptr;
	hashItem->Key = "";
	hashItem->Value = "";

	return hashItem;
}

