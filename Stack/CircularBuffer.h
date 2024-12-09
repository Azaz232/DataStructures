#pragma once

/// \brief Structure of the circular buffer
struct CircularBuffer
{
	/// \brief A pointer to the buffer
	int* Buffer;

	/// \brief Index for elements to write
	int Head;

	/// \brief Index for elements to read
	int Tail;

	/// \brief Capacity of the buffer
	int Capacity;

	/// \brief Number of elements currently in the buffer
	int Size;

	/// \brief Constructor for the circular buffer
	/// \param capacity Capacity of the buffer
	CircularBuffer(int capacity) : Capacity(capacity), Head(0), Tail(0), Size(0)
	{
		Buffer = new int[capacity];
	}
};

/// \brief Creates a circular buffer
/// \param capacity Capacity of the buffer
/// \return A pointer to the circular buffer
CircularBuffer* CreateCircularBuffer(int capacity);

/// \brief Checks for empty slots in the buffer
/// \param circularBuffer A pointer to the circular buffer
/// \return Number of empty slots
int FreeSpace(CircularBuffer* circularBuffer);

/// \brief Checks the number of occupied slots in the buffer
/// \param circularBuffer A pointer to the circular buffer
/// \return Number of occupied slots
int OccupiedSpace(CircularBuffer* circularBuffer);

/// \brief Adds an element to the buffer
/// \param circularBuffer A pointer to the circular buffer
/// \param data Data to insert
void Enqueue(CircularBuffer* circularBuffer, int data);

/// \brief Clears the buffer and frees memory
/// \param circularBuffer A pointer to the circular buffer
void DeleteCircularBuffer(CircularBuffer* circularBuffer);

/// \brief Removes an element from the circular buffer
/// \param circularBuffer A pointer to the circular buffer
/// \return Returns the removed value
int Dequeue(CircularBuffer* circularBuffer);

/// \brief Resizes the circular buffer
/// \param circularBuffer A pointer to the circular buffer
/// \param newCapacity New capacity of the buffer
void ResizeCircularBuffer(CircularBuffer* circularBuffer, int newCapacity);
