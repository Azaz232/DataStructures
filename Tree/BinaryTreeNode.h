#pragma once

/// \brief Structure representing a binary tree node
struct BinaryTreeNode
{
    /// \brief Data stored in the node
    int Data;

    /// \brief A pointer to the left child node
    BinaryTreeNode* Left;

    /// \brief A pointer to the right child node
    BinaryTreeNode* Right;

    ///// \brief A pointer to the parent node
    //BinaryTreeNode* Parent;

    /// \brief Constructor to initialize the binary tree node with default values
    BinaryTreeNode()
    {
        Data = 0;
        Left = nullptr;
        Right = nullptr;
        /*Parent = nullptr;*/
    }

    /// \brief Constructor to initialize the binary tree node with specified data
    /// \param data The data to set in the node
    BinaryTreeNode(int data)
    {
        Data = data;
        Left = nullptr;
        Right = nullptr;
        /*Parent = nullptr;*/
    }
};

/// \brief Creates a new node for the binary tree
/// \param data The data to set in the node
/// \return A pointer to the newly created node
BinaryTreeNode* CreateBinaryTreeNode(int data);

/// \brief Creates a new node for the binary tree with default data
/// \return A pointer to the newly created node
BinaryTreeNode* CreateBinaryTreeNode();

/// \brief Clears up the space used by the node
/// \param node A pointer to the node to delete
void DeleteBinaryTreeNode(BinaryTreeNode* node);
