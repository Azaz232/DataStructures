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

void AddNode(BinaryTreeNode*& root, int data)
{
	if (root == nullptr)
	{
		root = CreateBinaryTreeNode(data);
		return;
	}
	if (root->Data >= data)
	{
		AddNode(root->Left, data);
	}
	else
	{
		AddNode(root->Right, data);
	}
}

BinaryTreeNode* Search(BinaryTreeNode* node, int data)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	if (node->Data == data)
	{
		return node;
	}
	if (node->Data > data)
	{
		return Search(node->Left, data);
	}
	else
	{
		return Search(node->Right, data);
	}
}

BinaryTreeNode* FindMin(BinaryTreeNode* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	while (node->Left != nullptr)
	{
		node = node->Left;
	}
	return node;
}

BinaryTreeNode* FindMax(BinaryTreeNode* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	while (node->Right != nullptr)
	{
		node = node->Right;
	}
	return node;
}

void DeleteNode(BinaryTreeNode*& node, int data)
{
	if (node == nullptr)
	{
		return;
	}
	if (node->Data < data)
	{
		return DeleteNode(node->Right, data);
	}
	else if (node->Data > data)
	{
		return DeleteNode(node->Left, data);
	}
	else
	{
		if (node->Left == nullptr && node->Right == nullptr)
		{
			delete node;
			node = nullptr;
		}
		else if (node->Left == nullptr)
		{
			BinaryTreeNode* temp = node->Right;
			delete node;
			node = temp;
		}
		else if (node->Right == nullptr)
		{
			BinaryTreeNode* temp = node->Left;
			delete node;
			node = temp;
		}
		else
		{
			BinaryTreeNode* minNode = FindMin(node->Right);
			node->Data = minNode->Data;
			DeleteNode(node->Right, minNode->Data);
		}
	}
}
