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


int main()
{
    BinaryTree* binaryTree = CreateBinaryTree();

	while (true)
	{
        
		cout << "\tSelect the action you want to do: \n";
		cout << "1. Insert a node to the tree \n";
		

        int choice = GetInput("Enter your choice: ");

        switch (choice)
        {
        case 1:
        {
            int data = GetInput("Enter the value to insert to the binary tree");
            AddNode(binaryTree->Root, data);
        }
        default:
        {
            return;
        }


        }
	}

    DeleteBinaryTree(binaryTree);

}

