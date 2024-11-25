#pragma once
#include "Stack.h"

/// <summary>
/// Structure of the queue based on 2 stacks
/// </summary>
struct StackQueue
{
	/// <summary>
	/// The 1st stack
	/// </summary>
	Stack* FirstStack;

	/// <summary>
	/// the 2nd stack
	/// </summary>
	Stack* SecondStack;
};

/// <summary>
/// Creates a queue
/// </summary>
/// <param name="capacity"> capacity of the queue </param>
/// <returns> A pointer to the queue </returns>
StackQueue* CreateStackQueue(int capacity);

/// <summary>
/// Checks if the queue is full
/// </summary>
/// <param name="stack"> A pointer to the queue </param>
/// <returns> true if its full </returns>
bool IsFull(Stack* stack);

/// <summary>
/// Adds a value to the queue
/// </summary>
/// <param name="stackQueue"> A pointer to the queue </param>
/// <param name="data"> Value to add </param>
void EnqueueStack(StackQueue* stackQueue, int data);

/// <summary>
/// Deletes a value from the queue
/// </summary>
/// <param name="stackQueue"> A pointer to the queue </param>
/// <returns> Deleted value </returns>
int DequeueStack(StackQueue* stackQueue);

/// <summary>
/// Resizes the queue
/// </summary>
/// <param name="stackQueue"> A pointer to the queue </param>
/// <param name="newCapacity"> New capacity of the queue </param>
void ResizeStackQueue(StackQueue* stackQueue, int newCapacity);

/// <summary>
/// Clears memory from the queue
/// </summary>
/// <param name="stackQueue"> A pointer to the queue </param>
void DeleteStackQueue(StackQueue* stackQueue);
