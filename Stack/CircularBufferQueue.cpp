#include "CircularBufferQueue.h"
#include "CircularBuffer.h"

CircularBufferQueue* CreateCircularBufferQueue(int capacity)
{
	CircularBufferQueue* circularBufferQueue = new CircularBufferQueue;
	circularBufferQueue->CircularBuffer = CreateCircularBuffer(capacity);
	return circularBufferQueue;
}

void DeleCircularBufferQueue(CircularBufferQueue* circularBufferQueue)
{
	DeleteCircularBuffer(circularBufferQueue->CircularBuffer);
	delete circularBufferQueue;
}

void Enqueue(CircularBufferQueue* queue, int data)
{
	Enqueue(queue->CircularBuffer, data);
}

int Dequeue(CircularBufferQueue* queue)
{
	return Dequeue(queue->CircularBuffer);
}

bool IsEmpty(CircularBufferQueue* queue)
{
	return queue->CircularBuffer->Size == 0;
}

int Peek(CircularBufferQueue* queue)
{
	if (queue->CircularBuffer->Size == 0)
	{
		throw "queue id empty";
	}
	return queue->CircularBuffer->Buffer[queue->CircularBuffer->Tail];
}

void ResizeCircularBufferQueue(CircularBufferQueue* queue, int newCapacity)
{
	ResizeCircularBuffer(queue->CircularBuffer, newCapacity);
}
