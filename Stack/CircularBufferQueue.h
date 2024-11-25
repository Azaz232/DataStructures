#pragma once
#include "CircularBuffer.h"

/// <summary>
/// Structure of the circular buffer queue
/// </summary>
struct CircularBufferQueue
{
	/// <summary>
	/// A pointer to the circular buffer
	/// </summary>
	CircularBuffer* CircularBuffer;
};

/// <summary>
/// Creates a circular buffer queue
/// </summary>
/// <param name="capacity"> Capacity of the buffer </param>
/// <returns> A pointer to the queue </returns>
CircularBufferQueue* CreateCircularBufferQueue(int capacity);

/// <summary>
/// Clears space from the queue
/// </summary>
/// <param name="circularBufferQueue"> A pointer to the queue </param>
void DeleteCircularBufferQueue(CircularBufferQueue* circularBufferQueue);

/// <summary>
/// Inserts a value
/// </summary>
/// <param name="queue"> A pointer to the queue </param>
/// <param name="data"> Calue to insert </param>
void Enqueue(CircularBufferQueue* queue, int data);

/// <summary>
/// Deletes a value
/// </summary>
/// <param name="queue"> A pointer to the queue </param>
/// <returns> Deleted value </returns>
int Dequeue(CircularBufferQueue* queue);

/// <summary>
/// Checks if the queue is empty
/// </summary>
/// <param name="queue"> A pointer to the queue </param>
/// <returns> True if its empty </returns>
bool IsEmpty(CircularBufferQueue* queue);

int Peek(CircularBufferQueue* queue);

/// <summary>
/// Resizes the queue
/// </summary>
/// <param name="queue"> A pointer to the queue </param>
/// <param name="newCapacity"> New capacity of the queue </param>
void ResizeCircularBufferQueue(CircularBufferQueue* queue, int newCapacity);


