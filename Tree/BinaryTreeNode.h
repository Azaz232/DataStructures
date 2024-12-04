#pragma once

/// <summary>
/// Structure of the binary tree node
/// </summary>
struct BinaryTreeNode
{
	/// <summary>
	/// Data in the node
	/// </summary>
	int Data;

	/// <summary>
	/// A pointer to the left subsidiary node
	/// </summary>
	BinaryTreeNode* Left;

	/// <summary>
	/// A pointer to the right subsidiary node
	/// </summary>
	BinaryTreeNode* Right;

	/// <summary>
	/// A pointer to the parent node
	/// </summary>
	BinaryTreeNode* Parent;

	/// <summary>
	/// Constructor to initialize the binary tree node
	/// </summary>
	BinaryTreeNode()
	{
		Data = 0;
		Left = nullptr;
		Right = nullptr;
		Parent = nullptr;
	}

	/// <summary>
	/// Destructor  to clean up the space
	/// </summary>
	~BinaryTreeNode()
	{
		delete Left;
		delete Right;
	}

	BinaryTreeNode(int data)
	{
		Data = data;
		Left = nullptr;
		Right = nullptr;
		Parent = nullptr;
	}
};

/// <summary>
/// Creates a node for the binary tree
/// </summary>
/// <param name="data"> Data to set to the node </param>
/// <returns> A pointer to the node </returns>
BinaryTreeNode* CreateBinaryTreeNode(int data);
BinaryTreeNode* CreateBinaryTreeNode();

/// <summary>
/// Clears up the space from the node
/// </summary>
/// <param name="node"></param>
void DeleteBinaryTreeNode(BinaryTreeNode* node)
{
	delete node;
}


