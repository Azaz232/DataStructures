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

void InsertOptimized(TreapNode*& node, const int& key, const int& priority)
{
	if (node == nullptr)
	{
		node = CreateTreapNode(key, priority);;
		return;
	}
	if (node->Priority < priority)
	{
		TreapNode* left = nullptr;
		TreapNode* right = nullptr;
		Split(node, key, left, right);

		TreapNode* newNode = CreateTreapNode(key, priority);
		newNode->Left = left;
		newNode->Right = right;

		node = newNode;
	}
	else
	{
		if (node->Key < key)
		{
			InsertOptimized(node->Right, key, priority);
		}
		else
		{
			InsertOptimized(node->Left, key, priority);
		}
	}
}

void Delete(TreapNode*& node, const int& key)
{
	if (!node)
	{
		return;
	}

	TreapNode* left = nullptr;
	TreapNode* right = nullptr;
	TreapNode* middle = nullptr;

	Split(node, key - 1, left, middle);
	Split(middle, key, middle, right);

	if (middle)
	{
		delete middle;
		node = Merge(left, right);
	}
	else
	{
		node = Merge(left, middle);
	}
}

void DeleteOptimized(TreapNode*& node, const int& key)
{
	if (node == nullptr)
	{
		return;
	}
	if (node->Key == key)
	{
		TreapNode* temp = node;
		node = Merge(node->Left, node->Right);
		delete temp;
	}
	else if(node->Key < key)
	{
		DeleteOptimized(node->Right, key);
	}
	else
	{
		DeleteOptimized(node->Left, key);
	}
}


