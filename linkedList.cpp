#include "linkedList.h"
using namespace std;

LinkedList::LinkedList()
{
	head = nullptr;
	size = 0;
}

int LinkedList::getSize()
{
	return size;
}

bool LinkedList::isEmpty()
{
	return size == 0;
}

int LinkedList::value_at(int index)
{
	if (index < size) {
		Node* current = head;
		for (int i = 0; i < index; i++) {
			current = current->next;
		}
		return current->data;
	}
	return -1;
}

void LinkedList::push_front(int value)
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

int LinkedList::pop_front()
{
	if (size == 1) {
		Node* tempNode = head;
		delete[] head;
		size--;
		return tempNode->data;
	}
	else if (size > 1) {
		Node* tempNode = head;
		head = head->next;
		size--;
		return tempNode->data;
	}
	else return -1;
}

void LinkedList::push_back(int value)
{
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;
	if(size == 1) {
		head->next = newNode;
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

// check
int LinkedList::pop_back()
{
	if (size == 1) {
		Node* tempNode = head;
		delete[] head;
		size--;
		return tempNode->data;
	}
	else if (size > 1) {
		Node* current = head;
		Node* prev = nullptr;
		while (current->next != nullptr) {
			prev = current;
			current = current->next;
		}
		delete[] current;
		current = prev->next;
		prev->next = nullptr;
		size--;
		return current->data;
	}
	return -1;
}

int LinkedList::getFront()
{
	return head->data;
}

int LinkedList::getBack()
{
	if (size == 1) {
		return head->data;
	}
	else if (size > 1) {
		Node* current = head;
		while (current->next != nullptr)
			current = current->next;
		return current->data;
	}
	else {
		return -1;
	}
}

void LinkedList::insert(int index, int value)
{
	if (index > size) {
		cout << "Invalid index" << endl;
		return;
	}

	if (index == size) {
		push_back(value);
	}
	else if (index == 0) {
		push_front(value);
	}
	else {
		Node* newNode = new Node;
		newNode->data = value;
		newNode->next = nullptr;

		Node* current = head;
		Node* prev = nullptr;
		while (current->data != index) {
			prev = current;
			current = current->next;
		}
		newNode->next = prev->next;
		prev->next = newNode;
	}
	size++;
}

void LinkedList::erase(int index)
{
	if (index >= size) {
		cout << "Invalid index" << endl;
		return;
	}

	if (index == 0) {
		pop_front();
	}
	else if (index == size - 1) {
		pop_back();
	}
	else {
		Node* current = head;
		for (int i = 0; i < index; i++) {
			current = current->next;
		}
		if (current->next->next) {
			current->next = current->next->next;
		}
		else
			current->next = nullptr;
	}
}

int LinkedList::value_n_from_end(int n)
{
	if (size == 1) {
		return 0;
	}
}

void LinkedList::reverse() {
	if (head == nullptr || head->next == nullptr) {
		// If the list is empty or has only one node, no need to reverse
		return;
	}

	Node* prev = nullptr;
	Node* current = head;
	Node* nextNode = nullptr;

	while (current != nullptr) {
		nextNode = current->next; // Store the next node
		current->next = prev;     // Reverse the link

		// Move pointers one position ahead
		prev = current;
		current = nextNode;
	}

	// After the loop, prev will be pointing to the new head of the reversed list
	head = prev;
}


void LinkedList::display() {
	Node* current = head;
	while (current->next != nullptr) {
		cout << current->data << " ";
		current = current->next;
	}
}

LinkedList::~LinkedList()
{
	while (pop_front());
}



