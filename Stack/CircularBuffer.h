#pragma once

/// <summary>
/// Structure of the circular buffer
/// </summary>
struct CircularBuffer
{
	/// <summary>
	/// A pointer to the buffer
	/// </summary>
	int* Buffer;

	/// <summary>
	/// Index for elements to write
	/// </summary>
	int Head;

	/// <summary>
	/// Index for elements to get
	/// </summary>
	int Tail;
	
	/// <summary>
	/// Capacity of the buffer
	/// </summary>
	int Capacity;

	/// <summary>
	/// Amounts of elements
	/// </summary>
	int Size;

	/// <summary>
	/// Constructor for the circular buffer
	/// </summary>
	/// <param name="capacity"> Capacity of the buffer </param>
	CircularBuffer(int capacity) : Capacity(capacity), Head(0), Tail(0), Size(0)
	{
		Buffer = new int[capacity];
	}
};

/// <summary>
/// Created a circular buffer
/// </summary>
/// <param name="capacity"> Capacity of the buffer </param>
/// <returns> A pointer to the circular buffer </returns>
CircularBuffer* CreateCircularBuffer(int capacity);

/// <summary>
/// Check for empty slots in the buffer
/// </summary>
/// <param name="circularBuffer"> A pointer to the circular buffer </param>
/// <returns> amount of empty slots </returns>
int FreeSpace(CircularBuffer* circularBuffer);

/// <summary>
/// Checks the amount of occupied slots in the buffer
/// </summary>
/// <param name="circularBuffer"> A pointer to the circular buffer </param>
/// <returns> amount of occupied slots </returns>
int OccupiedSpace(CircularBuffer* circularBuffer);

/// <summary>
/// Adds an element to the buffer
/// </summary>
/// <param name="circularBuffer"> A pointer to the circular buffer </param>
/// <param name="data"> Data to insert </param>
void Enqueue(CircularBuffer* circularBuffer, int data);

/// <summary>
/// Clears space from the buffer
/// </summary>
/// <param name="circularBuffer"> A pointer to the circular buffer </param>
void DeleteCircularBuffer(CircularBuffer* circularBuffer);

/// <summary>
/// Deletes an element from the circular buffer
/// </summary>
/// <param name="circularBuffer"> A pointer to the circular buffer </param>
/// <returns> Returns deleted value </returns>
int Dequeue(CircularBuffer* circularBuffer);

/// <summary>
/// Resizes circular bufffer
/// </summary>
/// <param name="circularBuffer">  A pointer to the circular buffer </param>
/// <param name="newCapacity"> New capacity of the buffer </param>
void ResizeCircularBuffer(CircularBuffer* circularBuffer, int newCapacity);
