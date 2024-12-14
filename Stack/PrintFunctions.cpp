#include <iostream>
#include "Stack.h"
#include <string>
#include "CircularBuffer.h"
#include "CircularBufferQueue.h"
#include "StackQueue.h"

using namespace std;

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
        cout << circularBuffer->Buffer[(circularBuffer->Tail + i)
            % circularBuffer->Capacity] << " ";
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
