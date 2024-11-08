#include "List.h"

List* CreateLinkedList()
{
	List* linkedList = new List;

	linkedList->Size = 0;

	return linkedList;
}


void InsertAtBeginning(List* list, int value)
{
	Node* newNode = CreateNode();
	newNode->Data = value;
	newNode->Next = list->Head;

	if (list->Head != nullptr)
	{
		list->Head->Previous = newNode;
	}

	if (list->Tail == nullptr)
	{
		list->Tail = newNode;
	}

	list->Head = newNode;

	list->Size++;
}

void InsertAtEnd(List* list, int value)
{
	Node* newNode = CreateNode();
	newNode->Data = value;

	newNode->Previous = list->Tail;

	if (list->Tail != nullptr)
	{
		list->Tail->Next = newNode;
	}

	if (list->Head == nullptr)
	{
		list->Head = newNode;
	}

	list->Tail = newNode;
	list->Size++;
}

//Node* GetElement(List* list, int index)
//{
//	Node* currentNode = list->Head;
//	for (int i = 0; i < index; ++i)
//	{
//		if (currentNode == nullptr)
//		{
//			return currentNode;
//		}
//		currentNode = currentNode->Next;
//	}
//
//	return currentNode;
//}


void InsertAfter(List* list, int target, int data)
{
	Node* currentNode = list->Head;

	while (currentNode != nullptr)
	{
		if (currentNode->Data == target)
		{
			Node* newNode = CreateNode();
			newNode->Data = data;
			newNode->Next = currentNode->Next;
			newNode->Previous = currentNode;

			if (currentNode->Next != nullptr)
			{
				currentNode->Next->Previous = newNode;
			}
			currentNode->Next = newNode;

			if (currentNode == nullptr)
			{
				list->Head = newNode;
			}
			list->Size++;
		}
		currentNode = currentNode->Next;
	}
}

void InsertBefore(List* list, int target, int data)
{
	Node* currentNode = list->Head;

	while (currentNode != nullptr)
	{
		if (currentNode->Data == target)
		{
			Node* newNode = CreateNode();

			newNode->Data = data;
			newNode->Next = currentNode;
			newNode->Previous = currentNode->Previous;

			if (currentNode->Previous != nullptr)
			{
				currentNode->Previous->Next = newNode;
			}
		}
	}
}








void FreeList(List* list)
{
	Node* current = list->Head;
	while (current != nullptr) 
	{
		Node* nextNode = current->Next;
		delete current; 
		current = nextNode; 
	}
	delete list;
}

