#include "CircularBuffer.h"

CircularBuffer* CreateCircularBuffer(int capacity)
{
	return new CircularBuffer(capacity);
}

int FreeSpace(CircularBuffer* circularBuffer)
{
	return circularBuffer->Capacity - circularBuffer->Size;
}

int OccupiedSpace(CircularBuffer* circularBuffer)
{
	return circularBuffer->Size;
}

void Enqueue(CircularBuffer* circularBuffer, int data)
{
	if (circularBuffer->Size == circularBuffer->Capacity) 
	{
		circularBuffer->Tail = (circularBuffer->Tail + 1) % 
			circularBuffer->Capacity;
	}
	else 
	{
		circularBuffer->Size++;
	}
	circularBuffer->Buffer[circularBuffer->Head] = data;
	circularBuffer->Head = (circularBuffer->Head + 1) % 
		circularBuffer->Capacity;
}

int Dequeue(CircularBuffer* circularBuffer)
{
	if (OccupiedSpace(circularBuffer) == 0)
	{
		throw "Circular Buffer is empty";
	}
	int value = circularBuffer->Buffer[circularBuffer->Tail];
	circularBuffer->Tail = (circularBuffer->Tail + 1) % 
		circularBuffer->Capacity;
	--circularBuffer->Size;
	return value;
}

void ResizeCircularBuffer(CircularBuffer* circularBuffer, int newCapacity)
{
	int* newBuffer = new int[newCapacity];

	int elementsToCopy = (circularBuffer->Size < newCapacity) ? 
		circularBuffer->Size : newCapacity;
	
	for (int i = 0; i < elementsToCopy; i++)
	{
		int oldIndex = (circularBuffer->Tail + i) % circularBuffer->Capacity;
		newBuffer[i] = circularBuffer->Buffer[oldIndex];
	}

	delete[] circularBuffer->Buffer; 

	circularBuffer->Buffer = newBuffer; 
	circularBuffer->Capacity = newCapacity; 
	circularBuffer->Size = elementsToCopy;
	/*circularBuffer->Head = circularBuffer->Size; */
	circularBuffer->Head = elementsToCopy;
	circularBuffer->Tail = 0; 
}

void DeleteCircularBuffer(CircularBuffer* circularBuffer)
{
	delete[] circularBuffer->Buffer;
	delete circularBuffer;
}
