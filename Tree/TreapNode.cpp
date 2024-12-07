#include "TreapNode.h"

TreapNode* CreateTreapNode()
{
	return new TreapNode;
}

TreapNode* CreateTreapNode(const int& key, const int& priority)
{
	return new TreapNode(key, priority);
}

