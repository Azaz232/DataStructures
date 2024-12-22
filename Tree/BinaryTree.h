#pragma once
#include "BinaryTreeNode.h"

/// \brief Structure representing a binary tree
struct BinaryTree
{
    /// \brief A pointer to the root node of the tree
    BinaryTreeNode* Root;

    /// \brief Constructor to initialize the binary tree
    BinaryTree()
    {
        Root = nullptr;
    }
};

/// \brief Creates a new binary tree
/// \return A pointer to the newly created binary tree
BinaryTree* CreateBinaryTree();

/// \brief Clears up the space used by the binary tree
/// \param tree A pointer to the binary tree to delete
void DeleteBinaryTree(BinaryTree* tree);

/// \brief Adds a node to the binary tree
/// \param root A reference to a pointer to the root node
/// \param data The data to insert into the tree
//void AddNode(BinaryTreeNode*& root, int data);

void AddNode(BinaryTree*& binaryTree, const int& data);


/// \brief Searches for a node in the tree by its key
/// \param node A pointer to the node to search
/// \param data The data of the node to find
/// \return A pointer to the found node, or nullptr if not found
//BinaryTreeNode* Search(BinaryTreeNode* node, int data);

BinaryTreeNode* Search(BinaryTree* binaryTree, const int& data);



/// \brief Finds the minimum value in the binary tree
/// \param node A pointer to the root of the tree
/// \return A pointer to the node containing the minimum value
//BinaryTreeNode* FindMin(BinaryTreeNode* node);

BinaryTreeNode* FindMin(BinaryTree* binaryTree);



/// \brief Finds the maximum value in the binary tree
/// \param node A pointer to the root of the tree
/// \return A pointer to the node containing the maximum value
//BinaryTreeNode* FindMax(BinaryTreeNode* node);

BinaryTreeNode* FindMax(BinaryTree* binaryTree);


/// \brief Deletes a node from the tree by its key
/// \param node A reference to a pointer to the root node
/// \param data The data of the node to delete
//void DeleteNode(BinaryTreeNode*& node, int data);

bool DeleteNode(BinaryTree*& binaryTree, const int& data);

