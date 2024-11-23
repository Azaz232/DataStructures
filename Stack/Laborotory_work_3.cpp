#include <iostream>
#include "Stack.h"
#include <string>
#include "CircularBuffer.h"
#include "CircularBufferQueue.h"
#include "StackQueue.h"

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

void PrintStack(Stack* stack)
{
    cout << "\nStack contents: \n";
    for (int i = stack->Size - 1; i > -1; i--)
    {
        cout << stack->Buffer[i] << endl;
    }
    cout << endl;
}

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

void PrintCircularBufferQueue(CircularBufferQueue* queue)
{
    PrintCircularBuffer(queue->CircularBuffer);
}

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
		cout << "Select the action you want to do: \n";
        cout << "1. Push the value to stack \n";
        cout << "2. Pop the value from stack \n";
        cout << "3. Resize the stack \n";

        cout << "4. Write an element to the circular buffer \n";
        cout << "5. Read an element from the circular buffer \n";
        cout << "6. Resize the circular buffer \n";

        cout << "7. Enqueue the value to the circular buffer queue \n";
        cout << "8. Dequeue the circular buffer queue \n";
        cout << "9. Resize the circular buffer queue \n";

        cout << "10. Enqueue the value to the stack queue \n";
        cout << "11. Dequeue the value from the stack queue \n";
        cout << "12. Resize the stack queue \n";


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
            cout << endl << "i am not dumb i swear\ntail - " << circularBuffer->Tail << endl << "head- " << circularBuffer->Head << endl;
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