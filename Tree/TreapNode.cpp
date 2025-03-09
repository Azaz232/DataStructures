#include "TreapNode.h"
#include <iostream>

TreapNode* CreateTreapNode(const int& key)
{
	//TODO: nullptr
	srand(time(0));
	TreapNode* treapNode = new TreapNode;
	treapNode->Key = key;
	treapNode->Priority = rand() % 31;
	treapNode->Left = nullptr;
	treapNode->Right = nullptr;
	return treapNode;
}
