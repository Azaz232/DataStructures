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

    /// \brief Constructor to initialize a treap node with default values
    TreapNode()
    {
        Key = 0;
        Priority = 0;
        Left = nullptr;
        Right = nullptr;
    }

    /// \brief Constructor to initialize a treap node with specified key and priority
    /// \param key The key to set for the node
    /// \param priority The priority to set for the node
    TreapNode(const int& key, const int& priority)
    {
        Key = key;
        Priority = priority;
        Left = nullptr;
        Right = nullptr;
    }
};

/// \brief Creates a new treap node with default values
/// \return A pointer to the newly created treap node
TreapNode* CreateTreapNode();

/// \brief Creates a new treap node with specified key and priority
/// \param key The key to set for the node
/// \param priority The priority to set for the node
/// \return A pointer to the newly created treap node
TreapNode* CreateTreapNode(const int& key, const int& priority);
