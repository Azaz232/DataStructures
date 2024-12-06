#include "BinaryTreeNode.h"
#include "BinaryTree.h"
#include <iostream>
#include <string>

using namespace std;


/// <summary>
/// Checks whether the string is a number
/// </summary>
/// <param name="prompt"> Prompt </param>
/// <returns> True if the string is a number </returns>
bool isNumber(const string& msg)
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
/// <param name="prompt"> Prompt </param>
/// <returns> Number </returns>
int GetInput(const string& msg)
{
    string input;
    cout << msg;
    cin >> input;
    if (isNumber(input))
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
/// Prints binary tree
/// </summary>
/// <param name="root"></param>
/// <param name="space"></param>
/// <param name="count"></param>
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

void main()
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
		

        int choice = GetInput("Enter your choice: ");

        switch (choice)
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
                cout << "\nNode found: " << Search(binaryTree->Root, key)->Data;
            }
            break;
        }
        case 4:
        {
            if (FindMin(binaryTree->Root) != nullptr)
            {
            cout << "Min value in the tree: " << FindMin(binaryTree->Root)->Data;
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
                cout << "Max value in the tree: " << FindMax(binaryTree->Root)->Data;
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

    DeleteBinaryTree(binaryTree);

}

