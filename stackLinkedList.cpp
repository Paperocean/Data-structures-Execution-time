#include "stackLinkedL.h"

StackLinkedList::StackLinkedList()
{
	head = nullptr;
	size = 0;
}

StackLinkedList::~StackLinkedList()
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

void StackLinkedList::push(int value)
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

//int StackLinkedList::pop()
//{
//	if (size == 0) {
//		cout << "Stack is empty" << endl;
//		return -1;
//	}
//	else if (size == 1) {
//		int value = head->data;
//		head = nullptr;
//		size--;
//		return value;
//	}
//	else {
//		Node* temp = head;
//		int value = temp->data;
//		head = temp->next;
//		delete temp;
//		size--;
//		return value;
//	}
//}

int StackLinkedList::pop()
{
	if (size == 0) {
		cout << "Stack is empty" << endl;
		return -1;
	}
	else if (size == 1) {
		int value = head->data;
		head = nullptr;
		size--;
		return value;
	}
	else {
		Node* temp = head;
		int value = temp->data;
		head = temp->next;
		delete temp;
		size--;
		return value;
	}
}

void StackLinkedList::display()
{
	Node* current = head;
	while (current != nullptr) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}




