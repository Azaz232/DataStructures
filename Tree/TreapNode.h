#pragma once

/// <summary>
/// Structure of the treap node 
/// </summary>
struct TreapNode
{
	/// <summary>
	/// Key of the node
	/// </summary>
	int Key;  //   x

	/// <summary>
	/// Priority of the node
	/// </summary>
	int Priority;   //  y

	/// <summary>
	/// A pointer to the left child
	/// </summary>
	TreapNode* Left;

	/// <summary>
	/// A pointer to the right child
	/// </summary>
	TreapNode* Right;

	/// <summary>
	/// Constructor to initialize treap node
	/// </summary>
	TreapNode()
	{
		Key = 0;
		Priority = 0;
		Left = nullptr;
		Right = nullptr;
	}

	TreapNode(const int& key, const int& priority)
	{
		Key = key;
		Priority = priority;
		Left = nullptr;
		Right = nullptr;
	}
};


TreapNode* CreateTreapNode();

TreapNode* CreateTreapNode(const int& key, const int& priority);

