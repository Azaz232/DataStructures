#pragma once
#include "ListItem.h"

/// <summary>
/// Doubly linked list struct.
/// </summary>
struct List
{
	/// <summary>
	/// Pointer to the first element.
	/// </summary>
	Node* Head = nullptr;

	/// <summary>
	/// Pointer to the last element.
	/// </summary>
	Node* Tail = nullptr;

	/// <summary>
	/// Size of the list;
	/// </summary>
	int Size;
};


List* CreateLinkedList();

void InsertAtBeginning(List* list, int value);

void InsertAtEnd(List* list, int value);

void InsertAfter(List* list, int index, int data);


void FreeList(List* list);