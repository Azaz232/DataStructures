#include "Treap.h"

Treap* CreateTreap()
{
	return new Treap;
}

TreapNode* Search(Treap* treap, const int& key)
{
	if (treap->Root == nullptr)
	{
		return nullptr;
	}
	TreapNode* currentNode = treap->Root;
	while (currentNode)
	{
		if (currentNode->Key == key)
		{
			return currentNode;
		}
		if (currentNode->Key <= key)
		{
			currentNode = currentNode->Right;
		}
		else
		{
			currentNode = currentNode->Left;
		}
	}
	return nullptr;
}

void Split(TreapNode* node, const int& key, TreapNode*& left, TreapNode*& right)
{
	if (node == nullptr)
	{
		left = right = nullptr;
	}
	else if (node->Key <= key)
	{
		left = node;
		Split(node->Right, key, node->Right, right);

	}
	else if (node->Key >= key)
	{
		right = node;
		Split(node->Left, key, left, node->Left);
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

void DeleteTreap(TreapNode*& node)
{
	if (!node) return;

	DeleteTreap(node->Left);
	DeleteTreap(node->Right);

	delete node;
	node = nullptr;
}

void Insert(Treap*& treap, const int& key)
{
	TreapNode* newNode = CreateTreapNode(key);

	TreapNode* left = nullptr;
	TreapNode* right = nullptr;

	Split(treap->Root, key, left, right);

	treap->Root = Merge(Merge(left, newNode), right);
}

TreapNode* InsertOptimizedRecursion(TreapNode*& node, const int& key)
{
	if (node == nullptr)
	{
		return CreateTreapNode(key);
	}
	TreapNode* newNode = CreateTreapNode(key);
	if (newNode->Priority > node->Priority)
	{
		TreapNode* left = nullptr;
		TreapNode* right = nullptr;
		Split(node, key, left, right);

		newNode->Left = left;
		newNode->Right = right;

		node = newNode;
	}
	else
	{
		if (node->Key < key)
		{
			node->Right = InsertOptimizedRecursion(node->Right, key);
		}
		else
		{
			node->Left = InsertOptimizedRecursion(node->Left, key);
		}
	}
	return node;
}

void InsertOptimized(Treap*& treap, const int& key)
{
	treap->Root = InsertOptimizedRecursion(treap->Root, key);
}

void Delete(Treap*& treap, const int& key)
{
	TreapNode* deleteNode = Search(treap, key);
	if (deleteNode)
	{
		TreapNode* left = nullptr;
		TreapNode* right = nullptr;
		TreapNode* middle = nullptr;

		Split(treap->Root, key - 1, left, middle);
		Split(middle, key, middle, right);
		if (middle)
		{
			delete middle;
		}
		treap->Root = Merge(left, right);
	}
}

TreapNode* FindParentNode(Treap* treap, const int& key)
{
	TreapNode* parent = nullptr;
	TreapNode* current = treap->Root;
	while (current != nullptr)
	{
		if (key < current->Key)
		{
			parent = current;
			current = current->Left;
		}
		else if (key > current->Key)
		{
			parent = current;
			current = current->Right;
		}
		else
		{
			break;
		}
	}
	return parent;
}

void DeleteOptimized(Treap*& treap, const int& key)
{
	TreapNode* deleteNode = Search(treap, key);

	if (deleteNode)
	{
		TreapNode* left = deleteNode->Left;
		TreapNode* right = deleteNode->Right;

		TreapNode* mergedNode = Merge(left, right);

		if (deleteNode == treap->Root)
		{
			treap->Root = mergedNode;
		}
		else
		{
			TreapNode* parent = FindParentNode(treap, key);
			if (parent)
			{
				if (parent->Left == deleteNode)
				{
					parent->Left = mergedNode;
				}
				else
				{
					parent->Right = mergedNode;
				}
			}
		}
	}
	delete deleteNode;
}
