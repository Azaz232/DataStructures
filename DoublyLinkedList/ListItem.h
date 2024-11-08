#pragma once
// header file for definition of the node

/// <summary>
/// Structure of a node.
/// </summary>
struct Node
{
	/// <summary>
	/// Node value.
	/// </summary>
	int Data;

	/// <summary>
	/// Pointer to the next node.
	/// </summary>
	Node* Next = nullptr;
	
	/// <summary>
	/// Pointer to the previous node.
	/// </summary>
	Node* Previous = nullptr;
};


/// <summary>
/// Creation of the node.
/// </summary>
/// <returns> Returns created node. </returns>
Node* CreateNode();
