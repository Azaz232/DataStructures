#include <iostream>
#include "Stack.h"
#include <string>
#include "CircularBuffer.h"
#include "CircularBufferQueue.h"
#include "StackQueue.h"

using namespace std;

/// <summary>
/// Checks whether the string is a number
/// </summary>
/// <param name="prompt"> Prompt </param>
/// <returns> True if the string is a number </returns>
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

/// <summary>
/// Getsinput from the user
/// </summary>
/// <param name="prompt"> Prompt </param>
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
/// Gets users input for the size
/// </summary>
/// <param name="prompt"> Prompt </param>
/// <returns> Positive number </returns>
int PositiveSize(const string& msg)
{
    string input;
    cout << msg;
    cin >> input;
    if (!IsNumber(input) || stoi(input) <= 0)
    {
        cout << endl;
        cout << "Size must be positive or not be zero. \n";
        return PositiveSize(msg);
    }
    else
    {
        return stoi(input);
    }
}

/// <summary>
/// Prints stack
/// </summary>
/// <param name="stack"> A pointer to the stack </param>
void PrintStack(Stack* stack)
{
    cout << "\nStack contents: \n";
    for (int i = stack->Size - 1; i > -1; i--)
    {
        cout << stack->Buffer[i] << endl;
    }
    cout << endl;
}

/// <summary>
/// Prints circular buffer
/// </summary>
/// <param name="circularBuffer"> A pointer to the circular buffer </param>
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

/// <summary>
/// Prints circular buffer queue
/// </summary>
/// <param name="queue"> A pointer to the circular buffer queue </param>
void PrintCircularBufferQueue(CircularBufferQueue* queue)
{
    PrintCircularBuffer(queue->CircularBuffer);
}

/// <summary>
/// Prints stack queue
/// </summary>
/// <param name="stackQueue"> A pointer to the stack queue </param>
void PrintStackQueue(StackQueue* stackQueue)
{
    cout << "First stack:";
    PrintStack(stackQueue->FirstStack);
    cout << "Second stack:";
    PrintStack(stackQueue->SecondStack);
}

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
                return;
            }
            }
        }
    }
    DeleteStack(stack);
}

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
                return;
            }
            }
        }
    }
    DeleteCircularBuffer(circularBuffer);
}

void CircularBufferQueueController()
{
    int circularBufferQueueSize = PositiveSize("Enter the size of"
        " the circcular buffer queue: ");
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
                ResizeCircularBufferQueue(circularBufferQueue, newCapacity);
                break;
            }
            default:
            {
                return;
            }
            }
        }
    }
    DeleteCircularBufferQueue(circularBufferQueue);
}

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
                return;
            }
            }
        }
    }
    DeleteStackQueue(stackQueue);
}

//int main()
//{
//	int stackSize = PositiveSize("Enter size of stack: ");
//	Stack* stack = CreateStack(stackSize);
//
//    int circularBufferSize = PositiveSize("Enter the size of the circular buffer: ");
//    CircularBuffer* circularBuffer = CreateCircularBuffer(circularBufferSize);
//
//    int circularBufferQueueSize = PositiveSize("Enter the size of the circcular buffer queue: ");
//    CircularBufferQueue* circularBufferQueue = CreateCircularBufferQueue(circularBufferQueueSize);
//
//    int stackQueueSize = PositiveSize("Enter the size of the stack queue: ");
//    StackQueue* stackQueue = CreateStackQueue(stackQueueSize);
//
//	while (true)
//	{
//		cout << "\tSelect the action you want to do: \n";
//        cout << "1. Push the value to stack \n";
//        cout << "2. Pop the value from stack \n";
//        cout << "3. Resize the stack \n\n";
//
//        cout << "4. Write an element to the circular buffer \n";
//        cout << "5. Read an element from the circular buffer \n";
//        cout << "6. Resize the circular buffer \n\n";
//
//        cout << "7. Enqueue the value to the circular buffer queue \n";
//        cout << "8. Dequeue the circular buffer queue \n";
//        cout << "9. Resize the circular buffer queue \n\n";
//
//        cout << "10. Enqueue the value to the stack queue \n";
//        cout << "11. Dequeue the value from the stack queue \n";
//        cout << "12. Resize the stack queue \n\n";
//
//        int choice = GetInput("Enter ur choice: \n");
//
//        switch (choice)
//        {
//        case 1:
//        {
//            int value = GetInput("Enter the value to push: \n");
//            Push(stack, value);
//            PrintStack(stack);
//            break;
//        }
//        case 2:
//        {
//            int result = Pop(stack);
//            cout << "Element received " << result << endl;
//            PrintStack(stack);
//            break;
//        }
//        case 3:
//        {
//            int newSize = GetInput("Enter the new size of the stack \n");
//            ResizeStack(stack,newSize);
//            PrintStack(stack);
//            break;
//        }
//        case 4:
//        {
//            int value = GetInput("Enter the value you want to write to the circular buffer: \n");
//            Enqueue(circularBuffer, value);
//            PrintCircularBuffer(circularBuffer);
//            break;
//        }
//        case 5:
//        {
//            Dequeue(circularBuffer);
//            PrintCircularBuffer(circularBuffer);
//            break;
//        }
//        case 6:
//        {
//            PrintCircularBuffer(circularBuffer);
//            int newCapacity = GetInput("Enter the new size of the circular buffer: ");
//            ResizeCircularBuffer(circularBuffer, newCapacity);
//            PrintCircularBuffer(circularBuffer);
//            break;
//        }
//        case 7:
//        {
//            int value = GetInput("Enter the value to add: ");
//            cout << endl;
//            Enqueue(circularBufferQueue, value);
//            PrintCircularBufferQueue(circularBufferQueue);
//            cout << endl;
//            break;
//        }
//        case 8:
//        {
//            int value = Dequeue(circularBufferQueue);
//            cout << "Element received " << value << endl;
//            PrintCircularBufferQueue(circularBufferQueue);
//            break;
//        }
//        case 9:
//        {
//            int newCapacity = GetInput("Enter the new size of the circular buffer: ");
//            ResizeCircularBufferQueue(circularBufferQueue, newCapacity);
//            PrintCircularBufferQueue(circularBufferQueue);
//            break;
//        }
//        case 10:
//        {
//            int value = GetInput("Enter the value to add: ");
//            cout << endl;
//            EnqueueStack(stackQueue, value);
//            PrintStackQueue(stackQueue);
//            cout << endl;
//            break;
//        }
//        case 11:
//        {
//            int value = DequeueStack(stackQueue);
//            cout << "Element received " << value << endl;
//            PrintStackQueue(stackQueue);
//            break;
//        }
//        case 12:
//        {
//            PrintStackQueue(stackQueue);
//            int newCapacity = GetInput("Enter the new size of the stack queue: ");
//            ResizeStackQueue(stackQueue, newCapacity);
//            PrintStackQueue(stackQueue);
//            break;
//        }
//        default:
//        {
//            cout << "\nWrong command, try entering again\n";
//        }
//        }
//	}
//    DeleteStack(stack);
//    DeleteCircularBuffer(circularBuffer);
//    DeleteCircularBufferQueue(circularBufferQueue);
//    DeleteStackQueue(stackQueue);
//}

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

