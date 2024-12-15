#include "BinaryTreeNode.h"
#include "BinaryTree.h"
#include <iostream>
#include <string>
#include "TreapNode.h"
#include "Treap.h"

using namespace std;

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
        if (message[i]< '0' ||  message[i] > '9')
        {
            return false;
        }
    }
    return true;
}

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

string GetInputString(const string& message)
{
    string input;
    cout << message;
    cin >> input;
    return input;
}
