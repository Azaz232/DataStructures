#include <iostream>
#include <string>
#include "HashTable.h"

using namespace std;

bool IsNumber(const string& input)
{
    if (input.empty())
    {
        return false;
    }
    int start = 0;
    if (input[0] == '-' || input[0] == '+')
    {
        start = 1;
    }
    for (int i = start; i < input.size(); ++i)
    {
        if (input[i] < '0' || input[i] > '9')
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

int PositiveSize(const string& message)
{
    string input;
    cout << message;
    cin >> input;
    if (!IsNumber(input) || stoi(input) <= 0)
    {
        cout << endl;
        cout << "Size must be positive or not be zero. \n";
        return PositiveSize(message);
    }
    else
    {
        return stoi(input);
    }
}
