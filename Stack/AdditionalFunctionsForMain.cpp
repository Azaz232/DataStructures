#include <iostream>
#include "Stack.h"
#include <string>
#include "CircularBuffer.h"
#include "CircularBufferQueue.h"
#include "StackQueue.h"

using namespace std;

/// \brief  Checks whether the string is a number
/// \param input Users input
/// \return True if the string is a number
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
        if (!isdigit(input[i]))
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

/// \brief Gets user input for the size
/// \param message Prompt to display to the user
/// \return A positive number entered by the user
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

/// \brief Prints the contents of the stack
/// \param stack A pointer to the stack
void PrintStack(Stack* stack)
{
    cout << "\nStack contents: \n";
    for (int i = stack->Size - 1; i > -1; i--)
    {
        cout << stack->Buffer[i] << endl;
    }
    cout << endl;
}

/// \brief Prints the contents of the circular buffer
/// \param stack A pointer to the circular buffer
void PrintCircularBuffer(CircularBuffer* circularBuffer)
{
    if (OccupiedSpace(circularBuffer) == 0)
    {
        cout << "Buffer is empty. \n";
        return;
    }
    cout << "\nBuffer contents: \n";
    for (int i = 0; i < circularBuffer->Size; i++)
    {
        cout << circularBuffer->Buffer[(circularBuffer->Tail + i)
            % circularBuffer->Capacity] << " ";
    }
    cout << endl;
}

/// \brief Prints the contents of the circular buffer queue
/// \param stack A pointer to the circular buffer queue
void PrintCircularBufferQueue(CircularBufferQueue* queue)
{
    PrintCircularBuffer(queue->CircularBuffer);
}

/// \brief Prints the contents of the stack queue
/// \param stack A pointer to the stack queue
void PrintStackQueue(StackQueue* stackQueue)
{
    cout << "First stack:";
    PrintStack(stackQueue->FirstStack);
    cout << "Second stack:";
    PrintStack(stackQueue->SecondStack);
}

/// \brief Menu for the stack
void StackController()
{
    int stackSize = PositiveSize("Enter size of stack: ");
    Stack* stack = CreateStack(stackSize);

    while (true)
    {
        PrintStack(stack);

        cout << "\tSelect the action you want to do: \n";
        cout << "1. Push the value to stack \n";
        cout << "2. Pop the value from stack \n";
        cout << "3. Resize the stack \n";
        cout << "q - Quit  \n\n";

        string choice = GetInputString("Enter your choice: ");
        cout << endl;

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
                int newSize = GetInput("Enter the new size of the stack \n");
                ResizeStack(stack, newSize);
                break;
            }
            default:
            {
                cout << "Invalid choice. Please enter a number"
                    " between 1 and 3." << endl;
                break;
            }
            }
        }

    }
    DeleteStack(stack);
}

/// \brief Menu for the circular buffer
void CircularBufferController()
{
    int circularBufferSize = PositiveSize("Enter the size of"
        " the circular buffer: ");
    CircularBuffer* circularBuffer =
        CreateCircularBuffer(circularBufferSize);

    while (true)
    {
        PrintCircularBuffer(circularBuffer);

        cout << "\tSelect the action you want to do: \n";
        cout << "1. Write an element to the circular buffer \n";
        cout << "2. Read an element from the circular buffer \n";
        cout << "3. Resize the circular buffer \n";
        cout << "q - Quit  \n\n";

        string choice = GetInputString("Enter your choice: ");
        cout << endl;

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
                int value = GetInput("Enter the value you want to write"
                    " to the circular buffer: \n");
                Enqueue(circularBuffer, value);
                break;
            }
            case 2:
            {
                cout << "Element received " << Dequeue(circularBuffer) <<
                    endl;
                break;
            }
            case 3:
            {
                int newCapacity = GetInput("Enter the new size of "
                    "the circular buffer: ");
                ResizeCircularBuffer(circularBuffer, newCapacity);
                break;
            }
            default:
            {
                cout << "Invalid choice. Please enter a number"
                    " between 1 and 3." << endl;
                break;
            }
            }
        }
    }
    DeleteCircularBuffer(circularBuffer);
}

/// \brief Menu for the circular buffer
void CircularBufferQueueController()
{
    int circularBufferQueueSize = PositiveSize("Enter the size of"
        " the circular buffer queue: ");
    CircularBufferQueue* circularBufferQueue =
        CreateCircularBufferQueue(circularBufferQueueSize);

    while (true)
    {
        PrintCircularBufferQueue(circularBufferQueue);

        cout << "\tSelect the action you want to do: \n";
        cout << "1. Enqueue the value to the circular buffer queue \n";
        cout << "2. Dequeue the circular buffer queue \n";
        cout << "3. Resize the circular buffer queue \n";
        cout << "q - Quit  \n\n";

        string choice = GetInputString("Enter your choice: ");
        cout << endl;

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
                int value = GetInput("Enter the value to add: ");
                cout << endl;
                Enqueue(circularBufferQueue, value);
                break;
            }
            case 2:
            {
                int value = Dequeue(circularBufferQueue);
                cout << "Element received " << value << endl;
                break;
            }
            case 3:
            {
                int newCapacity = GetInput("Enter the new size of"
                    " the circular buffer: ");
                ResizeCircularBufferQueue(circularBufferQueue,
                    newCapacity);
                break;
            }
            default:
            {
                cout << "Invalid choice. Please enter a number"
                    " between 1 and 4." << endl;
                break;
            }
            }
        }
    }
    DeleteCircularBufferQueue(circularBufferQueue);
}

/// \brief Menu for the stack queue
void StackQueueController()
{
    int stackQueueSize = PositiveSize("Enter the size of the stack queue: ");
    StackQueue* stackQueue = CreateStackQueue(stackQueueSize);

    while (true)
    {
        PrintStackQueue(stackQueue);

        cout << "\tSelect the action you want to do: \n";
        cout << "1. Enqueue the value to the stack queue \n";
        cout << "2. Dequeue the value from the stack queue \n";
        cout << "3. Resize the stack queue \n";
        cout << "q - Quit  \n\n";

        string choice = GetInputString("Enter your choice: ");
        cout << endl;

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
                int value = GetInput("Enter the value to add: ");
                cout << endl;
                EnqueueStackQueue(stackQueue, value);
                cout << endl;
                break;
            }
            case 2:
            {
                int value = DequeueStackQueue(stackQueue);
                cout << "Element received " << value << endl;
                break;
            }
            case 3:
            {
                int newCapacity = GetInput("Enter the new size of the"
                    " stack queue: ");
                ResizeStackQueue(stackQueue, newCapacity);
                break;
            }
            default:
            {
                cout << "Invalid choice. Please enter a number"
                    " between 1 and 3." << endl;
                break;
            }
            }
        }
    }
    DeleteStackQueue(stackQueue);
}

/// \brief Main menu
void MainController()
{
    while (true)
    {
        cout << "\tSelect the structure to work with\n";
        cout << "1. Stack \n";
        cout << "2. Circular buffer \n";
        cout << "3. Circular buffer queue \n";
        cout << "4. Stack queue \n";
        cout << "q - Quit  \n\n";
        string choice = GetInputString("Your choice: ");
        cout << endl;

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
                StackController();
                break;
            }
            case 2:
            {
                CircularBufferController();
                break;
            }
            case 3:
            {
                CircularBufferQueueController();
                break;
            }
            case 4:
            {
                StackQueueController();
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
