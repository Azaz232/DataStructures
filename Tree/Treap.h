#pragma once
#include "TreapNode.h"

/// <summary>
/// Structure of the treap
/// </summary>
struct Treap
{
	/// <summary>
	/// A pointer to the root node of the treap
	/// </summary>
	TreapNode* Root;
	/// <summary>
	/// Constructor to initialize the treap
	/// </summary>
	Treap()
	{
		Root = nullptr;
	}
};

/// <summary>
/// Creates the treap
/// </summary>
/// <returns></returns>
Treap* CreateTreap();

/// <summary>
/// Clears memory
/// </summary>
/// <param name="node"> A pointer to the root of the treap </param>
void DeleteTreap(TreapNode* node);

/// <summary>
/// Inserts a node to the treap
/// </summary>
/// <param name="node"> A reference to a pointer of the treap root </param>
/// <param name="key"> Key of the node </param>
/// <param name="priority"> Priority of the node </param>
void Insert(TreapNode*& node, const int& key, const int& priority);

/// <summary>
/// Searches a node in the treap
/// </summary>
/// <param name="node"> A pointer to the root of the treap </param>
/// <param name="key"> Key to find in the treap </param>
/// <returns> A pointer to the found node </returns>
TreapNode* Search(TreapNode* node, const int& key);

/// <summary>
/// 
/// </summary>
/// <param name="node"></param>
/// <param name="key"></param>
/// <param name="priority"></param>
void InsertOptimized(TreapNode*& node, const int& key, const int& priority);

/// <summary>
/// 
/// </summary>
/// <param name="node">  </param>
/// <param name="key">    </param>
void Delete(TreapNode*& node, const int& key);

/// <summary>
/// 
/// </summary>
/// <param name="node"> </param>
/// <param name="key"> </param>
void DeleteOptimized(TreapNode*& node, const int& key);



