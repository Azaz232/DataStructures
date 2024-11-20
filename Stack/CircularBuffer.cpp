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
	if (FreeSpace(circularBuffer) == 0)
	{
		throw "Circular Buffer is filled \n";
	}
	else
	{
		if (circularBuffer->Head >= circularBuffer->Capacity)
		{
			circularBuffer->Head = 0;
		}
		circularBuffer->Buffer[circularBuffer->Head++];                          //////
		++circularBuffer->Size;
	}
}


int Dequeue(CircularBuffer* circularBuffer, int data)
{

}