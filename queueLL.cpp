#include "queueLL.h"

QueueLinkedList::QueueLinkedList()
{
	head = nullptr;
	size = 0;
}

QueueLinkedList::~QueueLinkedList() {
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

void QueueLinkedList::enqueueBeg(int value)
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

int QueueLinkedList::dequeueEnd()
{
	if (size == 1) {
		Node* tempNode = head;
		int data = tempNode->data;
		delete head;
		head = nullptr;
		size--;
		return data;
	}else if (size > 1) {
		Node* current = head;
		Node* prev = nullptr;
		while (current->next != nullptr) {
			prev = current;
			current = current->next;
		}
		prev->next = nullptr;
		int value = current->data;
		delete current;
		size--;
		return value;
	}
	return -1;
}

void QueueLinkedList::enqueueEnd(int value)
{
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;

	if (size == 0) {
		head = newNode;
	}
	else {
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNode;
	}
	size++;
}

int QueueLinkedList::dequeueBeg()
{
	if (size == 1) {
		Node* tempNode = head;
		int value = tempNode->data;
		delete head;
		head == nullptr;
		size--;
		return value;
	}
	else if (size > 1) {
		Node* tempNode = head;
		int value = tempNode->data;
		head = tempNode->next;
		delete tempNode;
		size--;
		return value;
	}
	return -1;
}


