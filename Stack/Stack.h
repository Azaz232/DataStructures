#pragma once

//! \brief Structure representing a stack.
struct Stack
{
	//! \brief Pointer to the array containing stack elements.
	int* Buffer;

	//! \brief Maximum size of the stack (capacity).
	int BufferSize;

	//! \brief Index of the last element in the stack.
	int Top;

	//! \brief Current number of elements in the stack.
	int Size;

	//! \brief Constructor for initializing the stack with a given size.
	//! \param size Size of the stack.
	Stack(int size) : BufferSize(size), Top(-1), Size(0)
	{
		Buffer = new int[BufferSize];
	}
};

//! \brief Creates a new stack with a specified size.
//! \param size Size of the stack to be created.
//! \return Pointer to the newly created stack.
Stack* CreateStack(int size);

//! \brief Adds a value to the top of the stack.
//! \param stack Pointer to the stack where the value will be added.
//! \param data Value to be added to the stack.
void Push(Stack* stack, int data);

//! \brief Removes a value from the top of the stack.
//! \param stack Pointer to the stack from which the value will be removed.
//! \return Value that was removed from the stack.
int Pop(Stack* stack);

//! \brief Frees the memory allocated for the stack.
//! \param stack Pointer to the stack to be deleted.
void DeleteStack(Stack* stack);

//! \brief Resizes the stack to a new capacity.
//! \param stack Pointer to the stack to be resized.
//! \param newSize New capacity of the stack.
void ResizeStack(Stack* stack, int newSize);

//! \brief Checks if the stack is empty.
//! \param stack Pointer to the stack to be checked.
//! \return true if the stack is empty; otherwise false.
bool IsEmpty(Stack* stack);