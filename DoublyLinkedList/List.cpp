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
			else
			{
				list->Head = newNode;
			}
			currentNode->Previous = newNode;
			list->Size++;
		}
		currentNode = currentNode->Next;
	}
}

void Remove(List* list, int index)
{
	if (index < 0 || index>list->Size)
	{
		throw "Index out of range \n";
		return;
	}

	Node* currentNode = list->Head;

	for (int i = 0; i < index; ++i)
	{
		currentNode = currentNode->Next;
	}

	if (currentNode == list->Head)
	{
		list->Head = currentNode->Next;
		if (list->Head != nullptr)
		{
			list->Head->Previous = nullptr;
		}
	}
	else if (currentNode == list->Tail)
	{
		list->Tail = currentNode->Previous;
		if (list->Tail != nullptr)
		{
			list->Tail->Next = nullptr;
		}

	}
	else
	{
		currentNode->Previous->Next = currentNode->Next;
		currentNode->Next->Previous = currentNode->Previous;
	}

	delete currentNode;
	list->Size--;
}

void Insert(List* list, int index, int data)
{
	if (index < 0 || index > list->Size-1)
	{
		throw "Index out of range";
		return;
	}

	Node* newNode = CreateNode();
	newNode->Data = data;

	if (index == 0)
	{
		newNode->Next = list->Head;
		newNode->Previous = nullptr;

		if (list->Head != nullptr)
		{
			list->Head->Previous = newNode;
		}

		list->Head = newNode;

		if (list->Tail == nullptr)
		{
			list->Tail = newNode;
		}
	}
	else if (index == list->Size-1)
	{
		newNode->Previous = list->Tail;
		newNode->Next = nullptr;

		if (list->Tail != nullptr)
		{
			list->Tail->Next = newNode;
		}

		list->Tail = newNode;

		if (list->Head == nullptr)
		{
			list->Head = newNode;
		}
	}
	else
	{
		Node* currentNode = list->Head;

		for (int i = 0; i < index; ++i)
		{
			currentNode = currentNode->Next;
		}

		newNode->Next = currentNode;
		newNode->Previous = currentNode->Previous;

		if (currentNode->Previous != nullptr)
		{
			currentNode->Previous->Next = newNode;
		}
		else
		{
			list->Head = newNode;
		}

		currentNode->Previous = newNode;
	}
	list->Size++;
}




Node* Search(List* list, int element)
{
	if (list == nullptr) 
	{
		throw ("hell nah");
		return nullptr;
	}

	Node* current = list->Head;
	while (current != nullptr) 
	{
		if (current->Data == element) 
		{
			return current;
		}
		current = current->Next;
	}
	return nullptr;
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

