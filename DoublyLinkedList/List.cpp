#include "List.h"

List* CreateLinkedList()
{
	List* linkedList = new List;

	linkedList->Size = 0;

	return linkedList;
}

/// <summary>
/// Finds a node in the list
/// </summary>
/// <param name="list"> Doubly linked list.  </param>
/// <param name="index"> Index. </param>
/// <returns> Pointer to the node. </returns>
Node* FindInList(List* list, int index)
{
	Node* currentNode = list->Head;

	for (int i = 0; i < index; ++i)
	{
		if (currentNode == nullptr)
		{
			return currentNode;
		}

		currentNode = currentNode->Next;
	}
	return currentNode;
}

/// <summary>
/// Checks whether the input value was in the range or not.
/// </summary>
/// <param name="list"> Doubly linked list. </param>
/// <param name="index"> Index. </param>
void CheckRange(List* list, int index)
{
	if (index < 0 || index>list->Size)
	{
		throw "Index out of range \n";
	}
}

/// <summary>
/// For elements in the beginning.
/// </summary>
/// <param name="list"> Doubly linked list. </param>
/// <param name="newNode"> Node that we insert. </param>
void HeadInsert(List* list, Node* newNode)
{
	if (list->Head != nullptr)
	{
		list->Head->Previous = newNode;
	}

	if (list->Tail == nullptr)
	{
		list->Tail = newNode;
	}

	list->Head = newNode;
}

/// <summary>
/// For elements at the end.
/// </summary>
/// <param name="list"> Doubly linked list. </param>
/// <param name="newNode"> Node that we insert. </param>
void TailInsert(List* list, Node* newNode)
{
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

/// <summary>
/// Inserts a node at index of a node
/// </summary>
/// <param name="list"> Doubly linked list. </param>
/// <param name="newNode"> Node that we need to insert. </param>
/// <param name="currentNode"> Node at which we need to insert. </param>
void InsertAt(List* list, Node* newNode, Node* currentNode)
{
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

void InsertAtBeginning(List* list, int value)
{
	Node* newNode = CreateNode();
	newNode->Data = value;
	newNode->Next = list->Head;

	HeadInsert(list, newNode);

	list->Size++;
}

void InsertAtEnd(List* list, int value)
{
	Node* newNode = CreateNode();
	newNode->Data = value;
	newNode->Previous = list->Tail;

	TailInsert(list, newNode);

	list->Size++;
}

void InsertAfter(List* list, int target, int data)
{
	Node* currentNode = list->Head;

	while (currentNode != nullptr)
	{
		// TODO: Дубль
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

			InsertAt(list, newNode, currentNode);

			list->Size++;
		}
		currentNode = currentNode->Next;
	}
}

void Remove(List* list, int index)
{
	CheckRange(list, index);

	Node* currentNode = FindInList(list, index);

	// TODO: Дубль
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
	CheckRange(list, index);

	Node* newNode = CreateNode();
	newNode->Data = data;

	if (index == 0)
	{
		newNode->Next = list->Head;
		newNode->Previous = nullptr;

		HeadInsert(list, newNode);
	}
	else if (index == list->Size-1)
	{
		newNode->Previous = list->Tail;
		newNode->Next = nullptr;

		TailInsert(list, newNode);
	}
	else
	{
		Node* currentNode = FindInList(list, index);
		
		InsertAt(list, newNode, currentNode);
	}
	list->Size++;
}

int LinearSearch(List* list, int element)
{
	Node* currentNode = list->Head;
	int index = 0;

	while (currentNode != nullptr)
	{
		if (currentNode->Data == element)
		{
			return index;
		}
		index++;
		currentNode = currentNode->Next;
	}
	return -1;
}

/// <summary>
/// Merges two halfs of a linked ilist into one recursively.
/// </summary>
/// <param name="left"> First part of the list. </param>
/// <param name="right"> Second part of the list. </param>
/// <returns> Returns the head of the merged list.</returns>
Node* Merge(Node* left, Node* right)
{
	if (!left)
	{
		return right;
	}

	if (!right)
	{
		return left;
	}

	if (left->Data < right->Data)
	{
		left->Next = Merge(left->Next, right);
		left->Next->Previous = left;
		left->Previous = nullptr;
		return left;
	}
	else
	{
		right->Next = Merge(left, right->Next);
		right->Next->Previous = right;
		right->Previous = nullptr;
		return right;
	}
}

/// <summary>
/// Splits th elist into two parts.
/// </summary>
/// <param name="head"> Head of the list. </param>
/// <returns> Returns the head of the second half of the list. </returns>
Node* Split(Node* head)
{
	Node* slow = head;
	Node* fast = head->Next;

	while (fast && fast->Next)
	{
		slow = slow->Next;
		fast = fast->Next->Next;
	}

	Node* temp = slow->Next;
	slow->Next = nullptr;
	if (temp)
	{
		temp->Previous = nullptr;
	}

	return temp;
}

/// <summary>
/// Merge sort of the list.
/// </summary>
/// <param name="head"> Head of the linked list. </param>
/// <returns> Head of the fully sorted list. </returns>
Node* MergeSort(Node* head)
{
	if (!head || !head->Next)
	{
		return head;
	}

	Node* secondHalf = Split(head);
	head = MergeSort(head);
	secondHalf = MergeSort(secondHalf);

	return Merge(head, secondHalf);
}

void Sort(List* list)
{
	list->Head = MergeSort(list->Head);

	Node* current = list->Head;
	list->Tail = nullptr; 

	while (current != nullptr)
	{
		list->Tail = current;
		current = current->Next;
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
