﻿#include "BinaryTree.h"

BinaryTree* CreateBinaryTree()
{
	return new BinaryTree;
}

void DeleteBinaryTree(BinaryTree* tree)
{
	DeleteBinaryTreeNode(tree->Root);
	delete tree;
}

//void AddNode(BinaryTreeNode*& root, int data)
//{
//	if (root == nullptr)
//	{
//		root = CreateBinaryTreeNode(data);
//		return;
//	}
//	if (root->Data >= data)
//	{
//		AddNode(root->Left, data);
//	}
//	else
//	{
//		AddNode(root->Right, data);
//	}
//}
//
//BinaryTreeNode* Search(BinaryTreeNode* node, int data)
//{
//	if (node == nullptr)
//	{
//		return nullptr;
//	}
//	if (node->Data == data)
//	{
//		return node;
//	}
//	if (node->Data > data)
//	{
//		return Search(node->Left, data);
//	}
//	else
//	{
//		return Search(node->Right, data);
//	}
//}
//
//BinaryTreeNode* FindMin(BinaryTreeNode* node)
//{
//	if (node == nullptr)
//	{
//		return nullptr;
//	}
//	while (node->Left != nullptr)
//	{
//		node = node->Left;
//	}
//	return node;
//}
//
//BinaryTreeNode* FindMax(BinaryTreeNode* node)
//{
//	if (node == nullptr)
//	{
//		return nullptr;
//	}
//	while (node->Right != nullptr)
//	{
//		node = node->Right;
//	}
//	return node;
//}
//
//void DeleteNode(BinaryTreeNode*& node, int data)
//{
//	if (node == nullptr)
//	{
//		return;
//	}
//	if (node->Data < data)
//	{
//		return DeleteNode(node->Right, data);
//	}
//	else if (node->Data > data)
//	{
//		return DeleteNode(node->Left, data);
//	}
//	else
//	{
//		if (node->Left == nullptr && node->Right == nullptr)
//		{
//			delete node;
//			node = nullptr;
//		}
//		else if (node->Left == nullptr)
//		{
//			BinaryTreeNode* temp = node->Right;
//			delete node;
//			node = temp;
//		}
//		else if (node->Right == nullptr)
//		{
//			BinaryTreeNode* temp = node->Left;
//			delete node;
//			node = temp;
//		}
//		else
//		{
//			BinaryTreeNode* minNode = FindMin(node->Right);
//			node->Data = minNode->Data;
//			DeleteNode(node->Right, minNode->Data);
//		}
//	}
//}



///////

BinaryTreeNode* FindInsertionNode(BinaryTree* binaryTree, const int& data)
{
	/*BinaryTreeNode* currentNode = binaryTree->Root;
	while (true)
	{
		if (currentNode->Data >= data)
		{
			if (currentNode->Right == nullptr)
			{
				return currentNode;
			}
			else
			{
				currentNode = currentNode->Right;
			}
		}
		else
		{
			if (currentNode->Left == nullptr)
			{
				return currentNode;
			}
			else
			{
				currentNode = currentNode->Left;
			}
		}
	}*/
	BinaryTreeNode* currentNode = binaryTree->Root;
	BinaryTreeNode* parentNode = nullptr;

	while (currentNode != nullptr)
	{
		parentNode = currentNode;
		if (data < currentNode->Data)
		{
			currentNode = currentNode->Left;
		}
		else
		{
			currentNode = currentNode->Right;
		}
	}
	return parentNode;
}

void AddNode(BinaryTree*& binaryTree, const int& data)
{
	BinaryTreeNode* newNode = CreateBinaryTreeNode(data);
	if (binaryTree->Root == nullptr)
	{
		binaryTree->Root = newNode;
		return;
	}
	else
	{
		BinaryTreeNode* insertionNode = FindInsertionNode(binaryTree, data);
		newNode->Parent = insertionNode;
		if (insertionNode->Data <= data)
		{
			insertionNode->Right = newNode;
		}
		else
		{
			insertionNode->Left = newNode;
		}
	}
}

//BinaryTreeNode* FindMin(BinaryTreeNode* node)
//{
//	while (node && node->Left != nullptr)
//	{
//		node = node->Left;
//	}
//	return node;
//}
//
//BinaryTreeNode* FindMax(BinaryTreeNode* node)
//{
//	while (node && node->Right != nullptr)
//	{
//		node = node->Right;
//	}
//	return node;
//}

BinaryTreeNode* FindMin(BinaryTree* binaryTree)
{
	if (binaryTree == nullptr || binaryTree->Root == nullptr)
	{
		return nullptr;
	}
	BinaryTreeNode* currentNode = binaryTree->Root;
	while (currentNode->Left != nullptr)
	{
		currentNode = currentNode->Left;
	}
	return currentNode;
}

BinaryTreeNode* FindMax(BinaryTree* binaryTree)
{
	if (binaryTree == nullptr || binaryTree->Root == nullptr)
	{
		return nullptr;
	}
	BinaryTreeNode* currentNode = binaryTree->Root;
	while (currentNode->Right != nullptr)
	{
		currentNode = currentNode->Right;
	}
	return currentNode;
}

BinaryTreeNode* Search(BinaryTree* binaryTree, const int& data)
{
	if (binaryTree == nullptr || binaryTree->Root == nullptr)
	{
		return nullptr;
	}
	BinaryTreeNode* currentNode = binaryTree->Root;
	while (currentNode != nullptr)
	{
		if (currentNode->Data == data)
		{
			return currentNode;
		}
		else if (currentNode->Data >= data)
		{
			currentNode = currentNode->Left;
		}
		else
		{
			currentNode = currentNode->Right;
		}
	}
	return nullptr;
}

void ChangeParentPointer(BinaryTreeNode* node, BinaryTreeNode* changeNode)
{
	BinaryTreeNode* parent = node->Parent;
	if (parent->Left == nullptr)
	{
		parent->Right = changeNode;
		return;
	}
	if (parent->Right == nullptr)
	{
		parent->Left = changeNode;
		return;
	}
	if (parent->Left->Data == node->Data)
	{
		parent->Left = changeNode;
	}
	else
	{
		parent->Right = changeNode;
	}
}


BinaryTreeNode* GetSmallestRightNode(BinaryTree* binaryTree, BinaryTreeNode* startNode)
{
	if (startNode->Right == nullptr)
	{
		return binaryTree->Root;
	}
	BinaryTreeNode* currentNode = startNode->Right;
	while (true)
	{
		if (currentNode->Left == nullptr)
		{
			return currentNode;
		}
		currentNode = currentNode->Left;
	}
}


bool DeleteNode(BinaryTree*& binaryTree, const int& data)
{
	BinaryTreeNode* deleteNode = Search(binaryTree, data);

	if (deleteNode == nullptr)
	{
		return false;
	}
	if (deleteNode == binaryTree->Root && binaryTree->Root->Left == nullptr
		&& binaryTree->Root->Right == nullptr)
	{
		delete binaryTree->Root;
		binaryTree->Root = nullptr;
		return true;
	}
	if (deleteNode->Left == nullptr && deleteNode->Right == nullptr)
	{
		ChangeParentPointer(deleteNode, nullptr);
		delete deleteNode;
		return true;
	}
	else if ((deleteNode->Left != nullptr && deleteNode->Right == nullptr)
		 || (deleteNode->Left == nullptr && deleteNode->Right != nullptr))
	{
		if (deleteNode->Left != nullptr)
		{
			ChangeParentPointer(deleteNode, deleteNode->Left);
		}
		else
		{
			ChangeParentPointer(deleteNode, deleteNode->Right);
		}
		return true;
	}
	else
	{
		BinaryTreeNode* smallestRightNode = 
			GetSmallestRightNode(binaryTree, deleteNode);
		if (smallestRightNode->Right == nullptr)
		{
			deleteNode->Data = smallestRightNode->Data;
			ChangeParentPointer(smallestRightNode, nullptr);
			delete smallestRightNode;
		}
		else
		{
			ChangeParentPointer(smallestRightNode, smallestRightNode->Right);
			deleteNode->Data = smallestRightNode->Data;
			smallestRightNode->Right->Parent = smallestRightNode->Parent;
			delete smallestRightNode;
		}
		return true;
	}
}


