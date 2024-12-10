#include "BinaryTreeNode.h"
#include "BinaryTree.h"
#include <iostream>
#include <string>
#include "TreapNode.h"
#include "Treap.h"

using namespace std;

/// \brief  Checks whether the string is a number
/// \param input Users input
/// \return True if the string is a number
bool IsNumber(const string& message)
{
    if (message.empty())
    {
        return false;
    }
    size_t start = 0;
    if (message[0] == '-' || message[0] == '+')
    {
        start = 1;
    }
    for (size_t i = start; i < message.size(); ++i)
    {
        if (!isdigit(message[i]))
        {
            return false;
        }
    }
    return true;
}

/// \brief Gets input from the user
/// \param message Prompt to display to the user
/// \return The number entered by the user
int GetInput(const string& message)
{
    string input;
    cout << message;
    cin >> input;
    if (IsNumber(input))
    {
        return stoi(input);
    }
    else
    {
        cout << "Unknown command. Try entering the command again." << endl;
        return GetInput(message);
    }
}

/// \brief Gets user input
/// \param message Message to display to the user
/// \return The string input provided by the user
string GetInputString(const string& message)
{
    string input;
    cout << message;
    cin >> input;
    return input;
}
