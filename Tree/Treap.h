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
void DeleteTreap(TreapNode* node);

/// \brief Inserts a node into the treap
/// \param node A reference to a pointer to the treap root
/// \param key The key of the node to insert
/// \param priority The priority of the node to insert
void Insert(TreapNode*& node, const int& key, const int& priority);

/// \brief Searches for a node in the treap
/// \param node A pointer to the root of the treap
/// \param key The key to find in the treap
/// \return A pointer to the found node, or nullptr if not found
TreapNode* Search(TreapNode* node, const int& key);

/// \brief Inserts a node into the treap with optimized logic
/// \param node A reference to a pointer to the treap root
/// \param key The key of the node to insert
/// \param priority The priority of the node to insert
void InsertOptimized(TreapNode*& node, const int& key, const int& priority);

/// \brief Deletes a node from the treap
/// \param node A reference to a pointer to the treap root
/// \param key The key of the node to delete
void Delete(TreapNode*& node, const int& key);

/// \brief Deletes a node from the treap with optimized logic
/// \param node A reference to a pointer to the treap root
/// \param key The key of the node to delete
void DeleteOptimized(TreapNode*& node, const int& key);
