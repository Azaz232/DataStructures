#pragma once
#include "Stack.h"

/// \brief Structure of the queue based on 2 stacks
struct StackQueue
{
    /// \brief The first stack
    Stack* FirstStack;

    /// \brief The second stack
    Stack* SecondStack;
};

/// \brief Creates a queue
/// \param capacity Capacity of the queue
/// \return A pointer to the queue
StackQueue* CreateStackQueue(int capacity);

/// \brief Checks if the queue is full
/// \param stack A pointer to the queue
/// \return True if the queue is full; otherwise false
bool IsFull(Stack* stack);

/// \brief Adds a value to the queue
/// \param stackQueue A pointer to the queue
/// \param data Value to add
void EnqueueStackQueue(StackQueue* stackQueue, int data);

/// \brief Deletes a value from the queue
/// \param stackQueue A pointer to the queue
/// \return The removed value
int DequeueStackQueue(StackQueue* stackQueue);

/// \brief Resizes the queue
/// \param stackQueue A pointer to the queue
/// \param newCapacity New capacity of the queue
void ResizeStackQueue(StackQueue* stackQueue, int newCapacity);

/// \brief Clears memory from the queue
/// \param stackQueue A pointer to the queue
void DeleteStackQueue(StackQueue* stackQueue);
