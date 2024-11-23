#pragma once
#include "Stack.h"

struct StackQueue
{
	Stack* FirstStack;
	Stack* SecondStack;
};

StackQueue* CreateStackQueue(int capacity);

bool IsFull(Stack* stack);

void EnqueueStack(StackQueue* stackQueue, int data);

int DequeueStack(StackQueue* stackQueue);

void ResizeStackQueue(StackQueue* stackQueue, int newCapacity);

void DeleteStackQueue(StackQueue* stackQueue);
