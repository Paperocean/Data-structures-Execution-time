#include "linkedListMalloc.h"

LinkedListMalloc::LinkedListMalloc()
{
	head = nullptr;
	size = 0;
}

LinkedListMalloc::~LinkedListMalloc()
{
	Node* current = head;
	Node* next = nullptr;
	while (current != nullptr) {
		next = current->next;
		delete current;
		current = next;
	}
	head = nullptr;
	size = 0;
}

void LinkedListMalloc::push_front(int value)
{
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;
	if (size == 0) {
		head = newNode;
	}
	else {
		newNode->next = head;
		head = newNode;
	}
	size++;
}

int LinkedListMalloc::pop_front()
{
	int value = -1;
	if (size == 1) {
		value = head->data;
		delete head;
		head = nullptr;
		size--;
	}
	else {
		Node* tempNode = head;
		value = tempNode->data;
		tempNode = tempNode->next;
		delete head;
		head = tempNode;
		size--;
	}
	return value;
}
