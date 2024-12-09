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
		return;
	}
	stack->Buffer[++stack->Top] = data;
	++stack->Size;
}

int Pop(Stack* stack)
{
	if (IsEmpty(stack))
	{
		return -1;
	}
	--stack->Size;
	return stack->Buffer[stack->Top--];
}

void ResizeStack(Stack* stack, int newSize)
{
	stack->BufferSize = newSize;	
	int* newBuffer = new int[newSize];

	int elementsToCopy = (stack->Size < newSize) ? stack->Size : newSize;

	for (int i = 0; i < elementsToCopy; i++)
	{
		newBuffer[i] = stack->Buffer[i];
	}

	delete[] stack->Buffer;
	stack->Buffer = newBuffer;
	stack->BufferSize = newSize;
	stack->Size = elementsToCopy;
	stack->Top = elementsToCopy - 1;
}
