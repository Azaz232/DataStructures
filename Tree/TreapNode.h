#pragma once

/// \brief Structure representing a treap node
struct TreapNode
{
    /// \brief Key of the node
    int Key;  ///< x

    /// \brief Priority of the node
    int Priority;  ///< y

    /// \brief A pointer to the left child
    TreapNode* Left;

    /// \brief A pointer to the right child
    TreapNode* Right;
};

/// \brief Creates a new treap node with specified key and priority
/// \param key The key to set for the node
/// \param priority The priority to set for the node
/// \return A pointer to the newly created treap node
TreapNode* CreateTreapNode(const int& key);
