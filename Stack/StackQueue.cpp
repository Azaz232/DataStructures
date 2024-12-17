#include "StackQueue.h"
#include "Stack.h"

StackQueue* CreateStackQueue(int capacity)
{
	StackQueue* stackQueue = new StackQueue;
	stackQueue->FirstStack = CreateStack(capacity);
	stackQueue->SecondStack = CreateStack(capacity);
	return stackQueue;
}

void DeleteStackQueue(StackQueue* stackQueue)
{
	DeleteStack(stackQueue->FirstStack);
	DeleteStack(stackQueue->SecondStack);
	delete stackQueue;
}

bool IsFull(Stack* stack)
{
	return stack->BufferSize - stack->Size;
}

void EnqueueStackQueue(StackQueue* stackQueue, int data)
{
	if (IsFull(stackQueue->FirstStack) == 0)
	{
		return;
	}
	Push(stackQueue->FirstStack, data);
}

int DequeueStackQueue(StackQueue* stackQueue)
{
	if (!IsEmpty(stackQueue->SecondStack))
	{
		return Pop(stackQueue->SecondStack);
	}
	while (!IsEmpty(stackQueue->FirstStack))
	{
		Push(stackQueue->SecondStack, Pop(stackQueue->FirstStack));
	}
	return Pop(stackQueue->SecondStack);
}

void ResizeStackQueue(StackQueue* stackQueue, int newCapacity)
{
	ResizeStack(stackQueue->FirstStack, newCapacity);
	ResizeStack(stackQueue->SecondStack, newCapacity);
}
