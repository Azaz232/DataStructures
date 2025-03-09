#include "BinaryTree.h"

BinaryTree* CreateBinaryTree()
{
	return new BinaryTree;
}

void DeleteBinaryTree(BinaryTree* tree)
{
	DeleteBinaryTreeNode(tree->Root);
	delete tree;
}

BinaryTreeNode* FindInsertionNode(BinaryTree* binaryTree, const int& data)
{
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

bool IsEmptyTree(BinaryTree* binaryTree)
{
	return (binaryTree == nullptr || binaryTree->Root == nullptr);
}

BinaryTreeNode* FindMin(BinaryTree* binaryTree)
{
	if (IsEmptyTree(binaryTree))
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
	if (IsEmptyTree(binaryTree))
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
	if (IsEmptyTree(binaryTree))
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

void ChangeParentPointer(BinaryTree*& binaryTree, BinaryTreeNode* node,
	BinaryTreeNode* changeNode)
{
	if (node == nullptr)
	{
		return; 
	}
	BinaryTreeNode* parent = node->Parent;
	if (parent == nullptr)
	{
		if (changeNode)
		{
			binaryTree->Root = changeNode;
			changeNode->Parent = nullptr;
		}
		return; 
	}
	if (parent->Left == node)
	{
		parent->Left = changeNode; 
	}
	else
	{
		parent->Right = changeNode;
	}
	if (changeNode != nullptr)
	{
		changeNode->Parent = parent;
	}
}

BinaryTreeNode* GetSmallestRightNode(BinaryTree* binaryTree,
	BinaryTreeNode* startNode)
{
	if (startNode->Right == nullptr)
	{
		return nullptr;
	}
	BinaryTreeNode* currentNode = startNode->Right;
	while (currentNode->Left != nullptr)
	{
		currentNode = currentNode->Left;
	}
	return currentNode;
}

void DeleteNode(BinaryTree*& binaryTree, const int& data)
{
	BinaryTreeNode* deleteNode = Search(binaryTree, data);

	if (deleteNode == nullptr)
	{
		return;
	}
	if (deleteNode == binaryTree->Root && deleteNode->Left == nullptr
		&& deleteNode->Right == nullptr)
	{
		delete binaryTree->Root;
		binaryTree->Root = nullptr;
		return;
	}
	if (deleteNode->Left == nullptr && deleteNode->Right == nullptr)
	{
		ChangeParentPointer(binaryTree, deleteNode, nullptr);
		delete deleteNode;
		return;
	}
	else if (deleteNode->Left != nullptr && deleteNode->Right == nullptr)
	{
		ChangeParentPointer(binaryTree, deleteNode, deleteNode->Left);
		delete deleteNode;
		return;
	}
	else if (deleteNode->Left == nullptr && deleteNode->Right != nullptr)
	{
		ChangeParentPointer(binaryTree, deleteNode, deleteNode->Right);
		delete deleteNode;
		return;
	}
	else
	{
		BinaryTreeNode* smallestRightNode =
			GetSmallestRightNode(binaryTree, deleteNode);
		if (smallestRightNode->Right == nullptr)
		{
			deleteNode->Data = smallestRightNode->Data;
			ChangeParentPointer(binaryTree, smallestRightNode, nullptr);
			delete smallestRightNode;
		}
		else
		{
			ChangeParentPointer(binaryTree, smallestRightNode,
				smallestRightNode->Right);
			deleteNode->Data = smallestRightNode->Data;
			smallestRightNode->Right->Parent = smallestRightNode->Parent;
			delete smallestRightNode;
		}
		return;
	}
}

