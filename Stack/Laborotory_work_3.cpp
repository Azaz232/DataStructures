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
/// Getsinput from the user
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
/// Gets users input for the size
/// </summary>
/// <param name="prompt"> Prompt </param>
/// <returns> Positive number </returns>
int PositiveSize(const string& msg)
{
    string input;
    cout << msg;
    cin >> input;
    if (!isNumber(input) || stoi(input) <= 0)
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
        cout << circularBuffer->Buffer[(circularBuffer->Tail + i) % circularBuffer->Capacity] << " ";
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

int main()
{
	int stackSize = PositiveSize("Enter size of stack: ");
	Stack* stack = CreateStack(stackSize);

    int circularBufferSize = PositiveSize("Enter the size of the circular buffer: ");
    CircularBuffer* circularBuffer = CreateCircularBuffer(circularBufferSize);

    int circularBufferQueueSize = PositiveSize("Enter the size of the circcular buffer queue: ");
    CircularBufferQueue* circularBufferQueue = CreateCircularBufferQueue(circularBufferQueueSize);

    int stackQueueSize = PositiveSize("Enter the size of the stack queue: ");
    StackQueue* stackQueue = CreateStackQueue(stackQueueSize);

	while (true)
	{
		cout << "\tSelect the action you want to do: \n";
        cout << "1. Push the value to stack \n";
        cout << "2. Pop the value from stack \n";
        cout << "3. Resize the stack \n\n";

        cout << "4. Write an element to the circular buffer \n";
        cout << "5. Read an element from the circular buffer \n";
        cout << "6. Resize the circular buffer \n\n";

        cout << "7. Enqueue the value to the circular buffer queue \n";
        cout << "8. Dequeue the circular buffer queue \n";
        cout << "9. Resize the circular buffer queue \n\n";

        cout << "10. Enqueue the value to the stack queue \n";
        cout << "11. Dequeue the value from the stack queue \n";
        cout << "12. Resize the stack queue \n\n";

        int choice = GetInput("Enter ur choice: \n");

        switch (choice)
        {
        case 1:
        {
            int value = GetInput("Enter the value to push: \n");
            Push(stack, value);
            PrintStack(stack);
            break;
        }
        case 2:
        {
            int result = Pop(stack);
            cout << "Element received " << result << endl;
            PrintStack(stack);
            break;
        }
        case 3:
        {
            int newSize = GetInput("Enter the new size of the stack \n");
            ResizeStack(stack,newSize);
            PrintStack(stack);
            break;
        }
        case 4:
        {
            int value = GetInput("Enter the value you want to write to the circular buffer: \n");
            Enqueue(circularBuffer, value);
            /*cout << endl << "i am not dumb i swear\ntail - " << circularBuffer->Tail << endl << "head- " << circularBuffer->Head << endl;*/
            PrintCircularBuffer(circularBuffer);
            break;
        }
        case 5:
        {
            Dequeue(circularBuffer);
            PrintCircularBuffer(circularBuffer);
            break;
        }
        case 6:
        {
            PrintCircularBuffer(circularBuffer);
            int newCapacity = GetInput("Enter the new size of the circular buffer: ");
            ResizeCircularBuffer(circularBuffer, newCapacity);
            PrintCircularBuffer(circularBuffer);
            break;
        }
        case 7:
        {
            int value = GetInput("Enter the value to add: ");
            cout << endl;
            Enqueue(circularBufferQueue, value);
            PrintCircularBufferQueue(circularBufferQueue);
            cout << endl;
            break;
        }
        case 8:
        {
            int value = Dequeue(circularBufferQueue);
            cout << "Element received " << value << endl;
            PrintCircularBufferQueue(circularBufferQueue);
            break;
        }
        case 9:
        {
            PrintCircularBuffer(circularBuffer);
            int newCapacity = GetInput("Enter the new size of the circular buffer: ");
            ResizeCircularBufferQueue(circularBufferQueue, newCapacity);
            PrintCircularBufferQueue(circularBufferQueue);
            break;
        }
        case 10:
        {
            int value = GetInput("Enter the value to add: ");
            cout << endl;
            EnqueueStack(stackQueue, value);
            PrintStackQueue(stackQueue);
            cout << endl;
            break;
        }
        case 11:
        {
            int value = DequeueStack(stackQueue);
            cout << "Element received " << value << endl;
            PrintStackQueue(stackQueue);
            break;
        }
        case 12:
        {
            PrintStackQueue(stackQueue);
            int newCapacity = GetInput("Enter the new size of the stack queue: ");
            ResizeStackQueue(stackQueue, newCapacity);
            PrintStackQueue(stackQueue);
            break;
        }
        default:
        {
            cout << "\nWrong command, try entering again\n";
        }
        }
	}
    DeleteStack(stack);
    DeleteCircularBuffer(circularBuffer);
    DeleteCircularBufferQueue(circularBufferQueue);
    DeleteStackQueue(stackQueue);
}