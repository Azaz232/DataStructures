#include "BinaryTreeNode.h"
#include "BinaryTree.h"
#include <iostream>
#include <string>
#include "TreapNode.h"
#include "Treap.h"
#include "InputFunctions.h"

using namespace std;

/// \brief Prints the contents of the binary tree
/// \param stack A pointer to the root
/// \param space Space between nodes
/// \param count Made to increase the space
void PrintBinaryTree(BinaryTreeNode* root, int space, int count)
{
    if (root == nullptr)
    {
        return;
    }
    space += count;
    PrintBinaryTree(root->Right, space, count);

    cout << endl;

    for (int i = count; i < space; i++)
    {
        cout << " ";
    }

    cout << root->Data << "\n";
    PrintBinaryTree(root->Left, space, count);
}

/// \brief Prints the contents of the treap
/// \param stack A pointer to the root
/// \param space Space between nodes
/// \param count Made to increase the space
void PrintTreap(TreapNode* root, int space, int count)
{
    if (root == nullptr)
    {
        return;
    }
    space += count;
    PrintTreap(root->Right, space, count);

    cout << endl;

    for (int i = count; i < space; i++)
    {
        cout << " ";
    }

    cout << root->Key << ", " << root->Priority << endl;
    PrintTreap(root->Left, space, count);
}

/// \brief Menu cintroller for the binary tree
void BinaryTreeController()
{
    BinaryTree* binaryTree = CreateBinaryTree();

    while (true)
    {

        PrintBinaryTree(binaryTree->Root, 0, 5);

        cout << "\tSelect the action you want to do: \n";
        cout << "1. Insert a node to the tree \n";
        cout << "2. Delete a node from the tree \n";
        cout << "3. Search a node in the tree \n";
        cout << "4. Search minimum \n";
        cout << "5. Search maximum \n";
        cout << "q - Quit  \n";


        string choice = GetInputString("Enter your choice: ");

        if (choice == "q")
        {
            break;
        }
        if (IsNumber(choice))
        {
            int intChoice = stoi(choice);
            switch (intChoice)
            {
                case 1:
                {
                    int data = GetInput("Enter the value to insert to "
                        "the binary tree: ");
                    AddNode(binaryTree, data);
                    break;
                }
                case 2:
                {
                    int data = GetInput("Node to delete from the tree: ");
                    if (!Search(binaryTree, data))
                    {
                        cout << "Theres no node with this value\n";
                        break;
                    }
                    else
                    {
                        DeleteNode(binaryTree, data);
                        break;
                    }
                }
                case 3:
                {
                    int key = GetInput("Enter the key of the node to "
                        "search: ");
                    if (Search(binaryTree, key) == nullptr)
                    {
                        cout << "\nNo node found \n";
                    }
                    else
                    {
                        cout << "\nNode " <<
                            Search(binaryTree, key)->Data << " found";

                    }
                    break;
                }
                case 4:
                {
                    if (FindMin(binaryTree) != nullptr)
                    {
                        cout << "Min value in the tree: " <<
                            FindMin(binaryTree)->Data;
                    }
                    else
                    {
                        cout << "Tree is empty \n";
                    }
                    break;
                }
                case 5:
                {
                    if (FindMax(binaryTree) != nullptr)
                    {
                        cout << "Max value in the tree: " <<
                            FindMax(binaryTree)->Data;
                    }
                    else
                    {
                        cout << "Tree is empty \n";
                    }
                    break;
                }
                default:
                {
                    cout << "Invalid choice. Please try again.\n" << endl;
                    break;
                }
            }
        }
        else
        {
            cout << "Invalid input. Please enter a number or 'q' to quit." <<
                endl;
        }
    }
    DeleteBinaryTree(binaryTree);
}

/// \brief Menu cintroller for the treap
void TreapController()
{
    Treap* treap = CreateTreap();

    while(true)
    {
        PrintTreap(treap->Root, 0, 5);

        cout << "\tSelect the action you want to do: \n";
        cout << "1. Search node \n";
        cout << "2. Insert a node to the treap \n";
        cout << "3. Insert a node to the treap(optimized) \n";
        cout << "4. Delete a node from the treap \n";
        cout << "5. Delete a node from the treap(optimized) \n";
        cout << "q - Quit\n";

        string choice = GetInputString("Enter your choice: ");

        if (choice == "q")
        {
            break;
        }
        if (IsNumber(choice))
        {
            int intChoice = stoi(choice);
            switch(intChoice)
            {
                case 1:
                {
                    int key = GetInput("Enter the key to find at the treap: ");
                    if (Search(treap, key) == nullptr)
                    {
                        cout << "No node found in the treap\n";
                    }
                    else
                    {
                        cout << "Node with key " << Search(treap, key)->Key << 
                            " found in the treap";
                    }
                    break;
                }
                case 2:
                {
                    int key = GetInput("Enter the key of the node: ");
                    Insert(treap, key);
                    break;
                }
                case 3:
                {
                    int key = GetInput("Enter the key of the node: ");
                    InsertOptimized(treap, key);
                    break;
                }
                case 4:
                {
                    int key = GetInput("Enter the key to delete: ");
                    if (Search(treap, key) == nullptr)
                    {
                        cout << "There is no such node\n";
                        break;
                    }
                    else
                    {
                        Delete(treap, key);
                        break;
                    }
                }
                case 5:
                {
                    int key = GetInput("Enter the key to delete: ");
                    if (Search(treap, key) == nullptr)
                    {
                        cout << "There is no such node\n";
                        break;
                    }
                    else
                    {
                        DeleteOptimized(treap, key);
                        break;
                    }
                }
                case 6:
                {
                    int key = GetInput("Enter the key to split ");
                    TreapNode* left = nullptr;
                    TreapNode* right = nullptr;
                    Split(treap->Root, key, left, right);
                    /*PrintTreap(left);*/

                    PrintTreap(left, 0, 5);

                    cout << endl << "______________________________________" << endl;

                    PrintTreap(right, 0, 5);
                    cout << endl << "______________________________________" << endl;
                    break;
                }
                default:
                {
                    cout << "Invalid choice. Please try again.\n" << endl;
                    break;
                }

            }
        }
        else
        {
            cout << "Invalid input. Please enter a number or 'q' to quit." <<
                endl;
        }
    }
    DeleteTreap(treap->Root);
}

void main()
{
    string menu = "\tChoose structure to work with:\n1.Binary tree\n2.Treap"
        "\nq - Quit\n";
    while (true)
    {
        cout << menu;
        string choice = GetInputString("Your choice: ");
        if (choice == "q") 
        {
            break;
        }
        if (IsNumber(choice))
        {
            int intChoice = stoi(choice);
            switch (intChoice)
            {
                case 1:
                {
                    BinaryTreeController();
                    break;
                }
                case 2:
                {
                    TreapController();
                    break;
                }
                default:
                {
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
            }
        }
        else
        {
            cout << "Invalid input. Please enter a number or 'q' to quit." <<
                endl;
        }
    }

}
