#include <iostream>
#include "Stack.h"
#include <string>
using namespace std;

bool isNumber(const string& prompt)
{
    if (prompt.empty())
    {
        return false;
    }

    size_t start = 0;
    if (prompt[0] == '-' || prompt[0] == '+')
    {
        start = 1;
    }

    for (size_t i = start; i < prompt.size(); ++i)
    {
        if (!isdigit(prompt[i]))
        {
            return false;
        }
    }

    return true;
}

int GetInput(const string& prompt)
{
    string input;
    cout << prompt;
    cin >> input;

    if (isNumber(input))
    {
        return stoi(input);
    }
    else
    {
        cout << endl;
        cout << "Unknown command. Try entering the command again." << endl;
        cout << endl;
        return GetInput(prompt);
    }
}

int PositiveSize(const string& prompt)
{
    string input;
    cout << prompt;
    cin >> input;

    if (!isNumber(input) || stoi(input) <= 0)
    {
        cout << endl;
        cout << "Size must be positive or not be zero. \n";
        return PositiveSize(prompt);
    }
    else
    {
        return stoi(input);
    }
}

int main()
{
	int StackSize = PositiveSize("Enter size of stack: \n");
	Stack* stack = CreateStack(StackSize);

	while (true)
	{
		for (int i = stack->BufferSize - 1; i > -1; i--)
		{
			cout << stack->Buffer[i] << endl;
		}


		cout << "Select the action you want to do: \n";
        cout << "1. Push the value to stack \n";
        cout << "2. Pop the value from stack \n";
        cout << "3. Resize the stack \n";


        int choice = GetInput("Enter ur choice: \n");

        switch (choice)
        {
        case 1:
        {
            int value = GetInput("Enter the value to push: \n");
            Push(stack, value);
            break;
        }
        case 2:
        {
            int result = Pop(stack);
            cout << "Element received " << result << endl;
            break;
        }
        case 3:
        {
            int newSize = GetInput("Enter the new size of the stack ");
            ResizeStack(stack,newSize);
            break;
        }
        }

	}
    DeleteStack(stack);
}