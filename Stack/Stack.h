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

	/// <summary>
	/// 
	/// </summary>
	int Size;

	/// <summary>
	/// Constructor 
	/// </summary>
	/// <param name="size"> Size of the stack </param>
	Stack(int size) : BufferSize(size), Top(-1), Size(0)
	{
		Buffer = new int[BufferSize];
	}
};

/// <summary>
/// Creates a stack
/// </summary>
/// <returns> returns a pointer to the stack </returns>
Stack* CreateStack(int size);

/// <summary>
/// Adds a value to the stack
/// </summary>
/// <param name="stack"> A pointer to the stack </param>
/// <param name="data"> Value to add </param>
void Push(Stack* stack, int data);

/// <summary>
/// Deletes a value from stack
/// </summary>
/// <param name="stack"> A pointer to stack </param>
/// <returns> Returns deleted value </returns>
int Pop(Stack* stack);

/// <summary>
/// Clears dynamically allocated memory 
/// </summary>
/// <param name="stack"> A pointer to the stack </param>
void DeleteStack(Stack* stack);

/// <summary>
/// Resizes stack
/// </summary>
/// <param name="stack"> A pointer to the stack </param>
/// <param name="newSize"> New cpacity of the stack </param>
void ResizeStack(Stack* stack, int newSize);

/// <summary>
/// Checks if the stack is empty
/// </summary>
/// <param name="stack"> A pointer to the stack </param>
/// <returns> True if its empty </returns>
bool IsEmpty(Stack* stack);



