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

/// <summary>
/// Creates a doubly linked list.
/// </summary>
/// <returns> returns a doubly linked list. </returns>
List* CreateLinkedList();

/// <summary>
/// Inserts an element at the beginning of the linked list.
/// </summary>
/// <param name="list"> Doubly linked list. </param>
/// <param name="value"> Value to insert. </param>
void InsertAtBeginning(List* list, int value);

/// <summary>
/// Inserts an element at the end of the linked list.
/// </summary>
/// <param name="list"> Doubly linked list. </param>
/// <param name="value"> Value to insert. </param>
void InsertAtEnd(List* list, int value);

/// <summary>
/// Inserts an element after a specific index.
/// </summary>
/// <param name="list"> Doubly linked list. </param>
/// <param name="index"> Index after which to insert.</param>
/// <param name="data"> Value to be inserted. </param>
void InsertAfter(List* list, int index, int data);

/// <summary>
/// Inserts an element before a specific index.
/// </summary>
/// <param name="list"> Doubly linked list. </param>
/// <param name="target"> Index before which to insert. </param>
/// <param name="data"> Value to be inserted.  </param>
void InsertBefore(List* list, int target, int data);

/// <summary>
/// Removes an element from the linked list.
/// </summary>
/// <param name="list"> Doubly linked list. </param>
/// <param name="index"> Value at which index to delete. </param>
void Remove(List* list, int index);

/// <summary>
/// Frees dynamically allocated memory.
/// </summary>
/// <param name="list"> Doubly linked list. </param>
void FreeList(List* list);


void Insert(List* list, int index, int data);


Node* Search(List* list, int element);
