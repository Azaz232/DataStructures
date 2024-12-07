#include "Treap.h"

Treap* CreateTreap()
{
	return new Treap;
}

TreapNode* Search(TreapNode* node, const int& key)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	if (node->Key == key)
	{
		return node;
	}
	if (node->Key < key)
	{
		return Search(node->Right, key);
	}
	else
	{
		return Search(node->Left, key);
	}
}

void Split(TreapNode* node, const int& key, TreapNode*& left, TreapNode*& right)
{
	if (node == nullptr)
	{
		left = right = nullptr;
	}
	else if (node->Key <= key)
	{
		Split(node->Right, key, node->Right, right);
		left = node;
	}
	else if (node->Key >= key)
	{
		Split(node->Left, key, left, node->Left);
		right = node;
	}
}

TreapNode* Merge(TreapNode* left, TreapNode* right)
{
	if (left == nullptr || right == nullptr)
	{
		return left == nullptr ? right : left;
	}
	if (left->Priority > right->Priority)
	{
		left->Right = Merge(left->Right, right);
		return left;
	}
	right->Left = Merge(left, right->Left);
	return right;
}

void DeleteTreap(TreapNode* node)
{
	if (!node) return;

	DeleteTreap(node->Left);
	DeleteTreap(node->Right);

	delete node;
	node = nullptr;
}

void Insert(TreapNode*& node, const int& key, const int& priority)
{
	TreapNode* newNode = CreateTreapNode(key, priority);

	TreapNode* left = nullptr;
	TreapNode* right = nullptr;

	Split(node, key, left, right);

	node = Merge(Merge(left, newNode), right);
}


