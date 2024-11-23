#pragma once
#include "CircularBuffer.h"

struct CircularBufferQueue
{
	CircularBuffer* CircularBuffer;

};

CircularBufferQueue* CreateCircularBufferQueue(int capacity);

void DeleteCircularBufferQueue(CircularBufferQueue* circularBufferQueue);

void Enqueue(CircularBufferQueue* queue, int data);

int Dequeue(CircularBufferQueue* queue);

bool IsEmpty(CircularBufferQueue* queue);

int Peek(CircularBufferQueue* queue);

void ResizeCircularBufferQueue(CircularBufferQueue* queue, int newCapacity);