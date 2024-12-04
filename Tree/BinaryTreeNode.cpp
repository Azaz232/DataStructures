#include "BinaryTreeNode.h"

BinaryTreeNode* CreateBinaryTreeNode(int data)
{
	return new BinaryTreeNode(data);
}

BinaryTreeNode* CreateBinaryTreeNode()
{
	return new BinaryTreeNode;
}

void DeleteBinaryTreeNode(BinaryTreeNode* node)
{
	delete node;
}
