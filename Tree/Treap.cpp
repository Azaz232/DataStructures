#include "Treap.h"

Treap* CreateTreap()
{
	return new Treap;
}
//
//TreapNode* Search(TreapNode* node, const int& key)
//{
//	if (node == nullptr)
//	{
//		return nullptr;
//	}
//	if (node->Key == key)
//	{
//		return node;
//	}
//	if (node->Key < key)
//	{
//		return Search(node->Right, key);
//	}
//	else
//	{
//		return Search(node->Left, key);
//	}
//}

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

//void Insert(TreapNode*& node, const int& key, const int& priority)
//{
//	TreapNode* newNode = CreateTreapNode(key, priority);
//
//	TreapNode* left = nullptr;
//	TreapNode* right = nullptr;
//
//	Split(node, key, left, right);
//
//	node = Merge(Merge(left, newNode), right);
//}

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

//void Delete(TreapNode*& node, const int& key)
//{
//	if (!node)
//	{
//		return;
//	}
//
//	TreapNode* left = nullptr;
//	TreapNode* right = nullptr;
//	TreapNode* middle = nullptr;
//
//	Split(node, key - 1, left, middle);
//	Split(middle, key, middle, right);
//
//	if (middle)
//	{
//		delete middle;
//		node = Merge(left, right);
//	}
//	else
//	{
//		node = Merge(left, middle);
//	}
//}

//TreapNode* FindDeleteNode(Treap* treap, const int& key)
//{
//	TreapNode* currentNode = treap->Root;
//	while (currentNode != nullptr)
//	{
//		if (key == currentNode->Key)
//		{
//			return currentNode; // Node found
//		}
//		else if (key < currentNode->Key)
//		{
//			currentNode = currentNode->Left; // Move to the left child
//		}
//		else
//		{
//			currentNode = currentNode->Right; // Move to the right child
//		}
//	}
//	return nullptr; // Node not found
//}

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

//void DeleteOptimized(TreapNode*& node, const int& key)
//{
//	if (node == nullptr)
//	{
//		return;
//	}
//	if (node->Key == key)
//	{
//		TreapNode* temp = node;
//		node = Merge(node->Left, node->Right);
//		delete temp;
//	}
//	else if(node->Key < key)
//	{
//		DeleteOptimized(node->Right, key);
//	}
//	else
//	{
//		DeleteOptimized(node->Left, key);
//	}
//}

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
