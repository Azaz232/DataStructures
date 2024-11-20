#include "Stack.h"

Stack* CreateStack(int size)
{
	return new Stack(size);
}

bool IsEmpty(Stack* stack)
{
	return stack->Top < 0;
}

void DeleteStack(Stack* stack)
{
	delete[] stack->Buffer;
	delete stack;
}

void Push(Stack* stack, int data)
{
	if (stack->Top >= stack->BufferSize - 1)
	{
		throw "Stack overflow!\n";
	}
	stack->Buffer[++stack->Top] = data;
}

int Pop(Stack* stack)
{
	if (IsEmpty(stack))
	{
		throw "Stack is empty \n";
	}
	return stack->Buffer[stack->Top--];
}

void ResizeStack(Stack* stack, int newSize)
{
	stack->BufferSize = newSize;
	int* newBuffer = new int[newSize];

	for (int i = stack->BufferSize - 1; i > -1; i-- )
	{
		newBuffer[i] = stack->Buffer[i];
	}

	delete[] stack->Buffer;
	stack->Buffer = newBuffer;
}