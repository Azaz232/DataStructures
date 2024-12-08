#include "BinaryTreeNode.h"
#include "BinaryTree.h"
#include <iostream>
#include <string>
#include "TreapNode.h"
#include "Treap.h"

using namespace std;

/// <summary>
/// Checks whether the string is a number
/// </summary>
/// <param name="prompt"> Prompt </param>
/// <returns> True if the string is a number </returns>
bool IsNumber(const string& msg)
{
    if (msg.empty())
    {
        return false;
    }
    size_t start = 0;
    if (msg[0] == '-' || msg[0] == '+')
    {
        start = 1;
    }
    for (size_t i = start; i < msg.size(); ++i)
    {
        if (!isdigit(msg[i]))
        {
            return false;
        }
    }
    return true;
}

/// <summary>
/// Gets input from the user
/// </summary>
/// <param name="msg"> Message </param>
/// <returns> Number </returns>
int GetInput(const string& msg)
{
    string input;
    cout << msg;
    cin >> input;
    if (IsNumber(input))
    {
        return stoi(input);
    }
    else
    {
        cout << "Unknown command. Try entering the command again." << endl;
        return GetInput(msg);
    }
}

/// <summary>
/// Gets users input
/// </summary>
/// <param name="msg"> Message </param>
/// <returns> String </returns>
string GetInputString(const string& msg)
{
    string input;
    cout << msg;
    cin >> input;
    return input;
}


/// <summary>
/// Prints binary tree
/// </summary>
/// <param name="root"> A pointer to the root of the binary tree </param>
/// <param name="space"> Space between printed nodes </param>
/// <param name="count"> Made to increase the space </param>
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

/// <summary>
/// Prints treap pairs
/// </summary>
/// <param name="root"> A pointer to the root of the treap </param>
/// <param name="space"> Space between printed nodes </param>
/// <param name="count"> Made to ibcrease the space </param>
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
                AddNode(binaryTree->Root, data);
                break;
            }
            case 2:
            {
                int data = GetInput("Node to delete from the tree: ");
                DeleteNode(binaryTree->Root, data);
                break;
            }
            case 3:
            {
                int key = GetInput("Enter the key of the node to search: ");
                if (Search(binaryTree->Root, key) == nullptr)
                {
                    cout << "\nNo node found \n";
                }
                else
                {
                    cout << "\nNode found: " << 
                        Search(binaryTree->Root, key)->Data;
                }
                break;
            }
            case 4:
            {
                if (FindMin(binaryTree->Root) != nullptr)
                {
                    cout << "Min value in the tree: " << 
                        FindMin(binaryTree->Root)->Data;
                }
                else
                {
                    cout << "Tree is empty \n";
                }
                break;
            }
            case 5:
            {
                if (FindMax(binaryTree->Root) != nullptr)
                {
                    cout << "Max value in the tree: " << 
                        FindMax(binaryTree->Root)->Data;
                }
                else
                {
                    cout << "Tree is empty \n";
                }
                break;
            }
            default:
            {
                return;
            }


            }
        }
    }
    DeleteBinaryTree(binaryTree);
}

void TreapController()
{
    Treap* treap = CreateTreap();

    while(true)
    {
        PrintTreap(treap->Root, 0, 5);

        cout << "\tSelect the action you want to do: \n";
        cout << "1. Insert a node to the treap \n";
        cout << "2. Search node \n";
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
                int key = GetInput("Enter the key of the node: ");
                int priority = GetInput("Enter the priority of the node: ");
                Insert(treap->Root, key, priority);
                break;
            }
            case 2:
            {
                int key = GetInput("Enter the key to find at the treap: ");
                if (Search(treap->Root, key) == nullptr)
                {
                    cout << "No node found in the treap\n";
                }
                else
                {
                    cout << "Node with key " << Search(treap->Root, key)->Key << " found in the treap";
                }
                break;
            }
            case 3:
            {
                int key = GetInput("Enter the key of the node: ");
                int priority = GetInput("Enter the priority of the node: ");
                InsertOptimized(treap->Root, key, priority);
                break;
            }
            case 4:
            {
                int key = GetInput("Enter the key to delete: ");
                Delete(treap->Root, key);
                break;
            }
            case 5:
            {
                int key = GetInput("Enter the key to delete: ");
                DeleteOptimized(treap->Root, key);
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



