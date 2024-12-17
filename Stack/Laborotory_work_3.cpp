#include <iostream>
#include "Stack.h"
#include <string>
#include "CircularBuffer.h"
#include "CircularBufferQueue.h"
#include "StackQueue.h"
#include "InputFunctions.h"
#include "PrintFunctions.h"

using namespace std;

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
                    if (IsFull(stack) == 0)
                    {
                        cout << "stack's full\n";
                    }
                    else
                    {
                        int value = GetInput("Enter the value to push: \n");
                        Push(stack, value);
                    }
                    break;
                }
                case 2:
                {
                    if (IsEmpty(stack))
                    {
                        cout << "stack is empty";
                    }
                    else
                    {
                        int result = Pop(stack);
                        cout << "Element received " << result << endl;
                    }
                    break;
                }
                case 3:
                {
                    int newSize = GetInput("Enter the new size of "
                        "the stack \n");
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
        else
        {
            cout << "Invalid input. Please enter a number or 'q' to quit." <<
                endl;
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
        else
        {
            cout << "Invalid input. Please enter a number or 'q' to quit." <<
                endl;
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
        else
        {
            cout << "Invalid input. Please enter a number or 'q' to quit." <<
                endl;
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
                    if (IsFull(stackQueue->FirstStack) == 0) 
                    {
                        cout << "stack is full\n\n";
                    }
                    else
                    {
                        int value = GetInput("Enter the value to add: ");
                        cout << endl;
                        EnqueueStackQueue(stackQueue, value);
                        cout << endl;
                    }
                    break;
                }
                case 2:
                {
                    if (IsEmpty(stackQueue->FirstStack) && IsEmpty(stackQueue->SecondStack))
                    {
                        cout << "stack is empty\n\n";
                    }
                    else
                    {
                        int value = DequeueStackQueue(stackQueue);
                        cout << "Element received " << value << endl;
                    }
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
        else
        {
            cout << "Invalid input. Please enter a number or 'q' to quit." <<
                endl;
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

int main()
{
    MainController();
}
