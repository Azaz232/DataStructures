#pragma once
#include "TreapNode.h"

/// \brief Structure representing a treap
struct Treap
{
    /// \brief A pointer to the root node of the treap
    TreapNode* Root;

    /// \brief Constructor to initialize the treap
    Treap()
    {
        Root = nullptr;
    }
};

/// \brief Creates a new treap
/// \return A pointer to the newly created treap
Treap* CreateTreap();

/// \brief Clears memory used by the treap
/// \param node A pointer to the root of the treap
void DeleteTreap(TreapNode*& node);

/// \brief Divides function into 2 sub-treaps
/// \param node A pointer to the treap root
/// \param key The key used to split the treap
/// \param left A reference to a pointer to the left sub-treap
/// \param right A reference to a pointer to the right sub-treap
void Split(TreapNode* node, const int& key, TreapNode*& left,
    TreapNode*& right);

/// \brief Combines 2 treaps into 1
/// \param left A pointer of the left sub-treap
/// \param right A pointer of the right sub-treap
/// \return A pointer to the root of the merged treap.
TreapNode* Merge(TreapNode* left, TreapNode* right);

/// \brief Inserts a node into the treap
/// \param node A reference to a pointer to the treap root
/// \param key The key of the node to insert
/// \param priority The priority of the node to insert
void Insert(Treap*& treap, const int& key);

/// \brief Searches for a node in the treap
/// \param node A pointer to the root of the treap
/// \param key The key to find in the treap
/// \return A pointer to the found node, or nullptr if not found
TreapNode* Search(Treap* treap, const int& key);

/// \brief Recursively inserts value to the treap
/// \param node A ref to a pointer of the root
/// \param key A key to insert 
/// \return A pointer to the treap with inserted value
TreapNode* InsertOptimizedRecursion(TreapNode*& node, const int& key);

/// \brief Inserts a node into the treap with optimized logic
/// \param node A reference to a pointer to the treap root
/// \param key The key of the node to insert
/// \param priority The priority of the node to insert
void InsertOptimized(Treap*& treap, const int& key);

/// \brief Deletes a node from the treap
/// \param node A reference to a pointer to the treap root
/// \param key The key of the node to delete
void Delete(Treap*& treap, const int& key);

/// \brief Manages pointers during deletion
/// \param treap A pointer to the treap root
/// \param key A key to delete
/// \return A pointer to the parent node of the deletion node
TreapNode* FindParentNode(Treap* treap, const int& key);

/// \brief Deletes a node from the treap with optimized logic
/// \param node A reference to a pointer to the treap root
/// \param key The key of the node to delete
void DeleteOptimized(Treap*& treap, const int& key);
