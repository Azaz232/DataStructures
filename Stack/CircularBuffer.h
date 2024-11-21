#pragma once

struct CircularBuffer
{
	int* Buffer;

	int Head;

	int Tail;
	
	int Capacity;

	int Size;

	CircularBuffer(int capacity) : Capacity(capacity), Head(0), Tail(0), Size(0)
	{
		Buffer = new int[capacity];
	}
};

CircularBuffer* CreateCircularBuffer(int capacity);

int FreeSpace(CircularBuffer* circularBuffer);

int OccupiedSpace(CircularBuffer* circularBuffer);

void Enqueue(CircularBuffer* circularBuffer, int data);

void DeleteCircularBuffer(CircularBuffer* circularBuffer);

int Dequeue(CircularBuffer* circularBuffer);

void ResizeCircularBuffer(CircularBuffer* circularBuffer, int newCapacity);
