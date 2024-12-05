#pragma once
#include "BinaryTreeNode.h"

/// <summary>
/// Structure of the binary tree
/// </summary>
struct BinaryTree
{
	/// <summary>
	/// A pointer to the root node of the tree
	/// </summary>
	BinaryTreeNode* Root;

	/// <summary>
	/// Constructor to initialize the binary tree
	/// </summary>
	BinaryTree()
	{
		Root = nullptr;
	}
};

/// <summary>
/// Creates binary tree
/// </summary>
/// <returns> A pointer to the root of the binary tree </returns>
BinaryTree* CreateBinaryTree();

/// <summary>
/// Clears up the space from the binary tree
/// </summary>
/// <param name="root"></param>
void DeleteBinaryTree(BinaryTree* tree);

/// <summary>
/// Adds a node to the tree
/// </summary>
/// <param name="node">  </param>
/// <param name="data"></param>
void AddNode(BinaryTreeNode*& root, int data);


