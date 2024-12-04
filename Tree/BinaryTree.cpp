#include "BinaryTree.h"

BinaryTree* CreateBinaryTree()
{
	return new BinaryTree;
}

void DeleteBinaryTree(BinaryTree* root)
{
	delete root;
}

void AddNode(BinaryTreeNode* root, int data)
{
	if (root == nullptr)
	{
		root = CreateBinaryTreeNode(data);
		return;
	}
	if (root->Data <= data)
	{
		return AddNode(root->Left, data);
	}
	else
	{
		return AddNode(root->Right, data);
	}
}

void DeleteNode(BinaryTreeNode* root, int data)
{
	if (root == nullptr)
	{
		return;
	}
	if (root->Data < data)
	{
		return DeleteNode(root->Left, data);
	}
	else if (root->Data > data)
	{
		return DeleteNode(root->Right, data);
	}
	else
	{
		if (root->Left)
		{

		}
	}
}
