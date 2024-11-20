#pragma once

struct CircularBuffer
{
	int* Buffer;

	int Head;

	int Tail;
	
	int Capacity;

	int Size;

	CircularBuffer(int capacity) : Capacity(capacity), Head(0), Tail(0)
	{
		Buffer = new int[capacity];
	}
};

