#pragma once

/// <summary>
/// Structure of a stack
/// </summary>
struct Stack
{
	/// <summary>
	/// A pointer to an array of elements
	/// </summary>
	int* Buffer;
	/// <summary>
	/// Size of a Buffer
	/// </summary>
	int BufferSize;

	/// <summary>
	/// Index of the last element
	/// </summary>
	int Top;

	int Size;

	Stack(int size) : BufferSize(size), Top(-1), Size(0)
	{
		Buffer = new int[BufferSize];
	}
};

/// <summary>
/// Creates a stack
/// </summary>
/// <returns>returns a pointer to the stack</returns>
Stack* CreateStack(int size);

void Push(Stack* stack, int data);

int Pop(Stack* stack);

void DeleteStack(Stack* stack);

void ResizeStack(Stack* stack, int newSize);

bool IsEmpty(Stack* stack);