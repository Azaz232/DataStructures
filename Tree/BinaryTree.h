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

/// <summary>
/// Searches a node in a tree by the key
/// </summary>
/// <param name="node"> A pointer to the node </param>
/// <param name="data"> A data of the node to find </param>
/// <returns> A pointer to the found node </returns>
BinaryTreeNode* Search(BinaryTreeNode* node, int data);

/// <summary>
/// Finds minimum number in the tree
/// </summary>
/// <param name="node"> A pointer to the root of the tree </param>
/// <returns> A pointer to the node </returns>
BinaryTreeNode* FindMin(BinaryTreeNode* node);

/// <summary>
/// Finds maximum number in the tree
/// </summary>
/// <param name="node"> A pointer to the root of the tree </param>
/// <returns> A pointer to the node </returns>
BinaryTreeNode* FindMax(BinaryTreeNode* node);

/// <summary>
/// Deletes a node from the tree by key
/// </summary>
/// <param name="node">  A reference to a pointer to the root node </param>
/// <param name="data">  </param>
/// <param name="data"> Locates the node to delete </param>
void DeleteNode(BinaryTreeNode*& node, int data);
