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
	//if (FreeSpace(circularBuffer) == 0)
	//{
	//	throw "Circular Buffer is full";
	//}
	//if (circularBuffer->Head >= circularBuffer->Capacity)
	//{
	//	circularBuffer->Head = 0;
	//}
	///*circularBuffer->Buffer[circularBuffer->Head] = data; */
	///*circularBuffer->Head = (circularBuffer->Head + 1) % circularBuffer->Capacity;*/
	//circularBuffer->Buffer[circularBuffer->Head++] = data;
	//++circularBuffer->Size;

	if (circularBuffer->Size == circularBuffer->Capacity) 
	{
		/*circularBuffer->Head = (circularBuffer->Head) % circularBuffer->Capacity;*/
		circularBuffer->Tail = (circularBuffer->Tail + 1) % circularBuffer->Capacity;
		/*circularBuffer->Tail++;*/
		/*circularBuffer->Head = 0;*/
	}
	else 
	{
		circularBuffer->Size++;
	}
	circularBuffer->Buffer[circularBuffer->Head] = data;
	circularBuffer->Head = (circularBuffer->Head + 1) % circularBuffer->Capacity;
}


int Dequeue(CircularBuffer* circularBuffer)
{
	if (OccupiedSpace(circularBuffer) == 0)
	{
		throw "Circular Buffer is empty";
	}
	int value = circularBuffer->Buffer[circularBuffer->Tail];
	circularBuffer->Tail = (circularBuffer->Tail + 1) % circularBuffer->Capacity;
	--circularBuffer->Size;
	return value;
}

void ResizeCircularBuffer(CircularBuffer* circularBuffer, int newCapacity)
{
	/*circularBuffer->Capacity = newCapacity;
	int* newBuffer = new int[newCapacity];

	for (int i = 0; i < circularBuffer->Size; i++)
	{
		newBuffer[i] = circularBuffer->Buffer[i];
	}

	delete[] circularBuffer->Buffer;
	circularBuffer->Buffer = newBuffer;*/

	int* newBuffer = new int[newCapacity];

	for (int i = 0; i < circularBuffer->Size; i++)
	{
		// Calculate the index in the old buffer
		int oldIndex = (circularBuffer->Tail + i) % circularBuffer->Capacity;
		newBuffer[i] = circularBuffer->Buffer[oldIndex];
	}

	delete[] circularBuffer->Buffer; 
	circularBuffer->Buffer = newBuffer; 
	circularBuffer->Capacity = newCapacity; 
	circularBuffer->Head = circularBuffer->Size; 
	circularBuffer->Tail = 0; 


}

void DeleteCircularBuffer(CircularBuffer* circularBuffer)
{
	delete[] circularBuffer->Buffer;
	delete circularBuffer;
}