#pragma once
#include "CircularBuffer.h"

/// \brief Structure of the circular buffer queue
struct CircularBufferQueue
{
    /// \brief A pointer to the circular buffer
    CircularBuffer* CircularBuffer;
};

/// \brief Creates a circular buffer queue
/// \param capacity Capacity of the buffer
/// \return A pointer to the queue
CircularBufferQueue* CreateCircularBufferQueue(int capacity);

/// \brief Clears the queue and frees memory
/// \param circularBufferQueue A pointer to the queue
void DeleteCircularBufferQueue(CircularBufferQueue* circularBufferQueue);

/// \brief Inserts a value into the queue
/// \param queue A pointer to the queue
/// \param data Value to insert
void Enqueue(CircularBufferQueue* queue, int data);

/// \brief Removes a value from the queue
/// \param queue A pointer to the queue
/// \return The removed value
int Dequeue(CircularBufferQueue* queue);

/// \brief Checks if the queue is empty
/// \param queue A pointer to the queue
/// \return True if the queue is empty; otherwise false
bool IsEmpty(CircularBufferQueue* queue);

/// \brief Resizes the queue
/// \param queue A pointer to the queue
/// \param newCapacity New capacity of the queue
void ResizeCircularBufferQueue(CircularBufferQueue* queue, int newCapacity);
