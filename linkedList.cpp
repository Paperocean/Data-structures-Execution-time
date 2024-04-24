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
		delete head;
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

	if (size == 0) {
		head = newNode;
	}
	else if(size == 1) {
		head->next = newNode;
	}
	else {
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		// current is the last node
		current->next = newNode;
	}
	size++;
}

int LinkedList::pop_back() {
	if (size == 1) {
		Node* tempNode = head;
		int data = tempNode->data;
		delete head;
		head = nullptr;
		size--;
		return data;
	}
	else if (size > 1) {
		Node* current = head;
		Node* prev = nullptr;
		Node* tempNode = nullptr;

		while (current->next != nullptr) {
			prev = current;
			current = current->next;
		}
		tempNode = current;
		prev->next = nullptr;
		int data = tempNode->data;
		delete current;
		size--;
		return data;
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
		for (int i = 0; i < index; i++) {
			prev = current;
			current = current->next;
		}
		newNode->next = current;
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

void LinkedList::display() {
	Node* current = head;
	while (current != nullptr) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

void LinkedList::remove_value(int value)
{
	if (size < 1) {
		cout << "List is empty" << endl;
		return;
	}

	if (head->data == value) {
		pop_front();
		return;
	}
	else {
		Node* current = head;
		Node* prev = nullptr;

		while (current->next != nullptr) {
			prev = current;
			current = current->next;
			if (current->data == value) {
				prev->next = current->next;
				delete current;
				size--;
				return;
			}
		}
	}
}

bool LinkedList::isCycle() {
	Node* tortoise = head;
	Node* hare = head;

	while (hare->next != nullptr && hare->next->next != nullptr) {
		tortoise = tortoise->next;
		hare = hare->next->next;
		if (hare == tortoise) return true;
	}
	return false;
}

void LinkedList::makeCycle()
{
	Node* newNode = new Node;
	newNode->data = 1;
	newNode->next = nullptr;
	head = newNode;

	for (int i = 0; i < 9; i++) {
		newNode = new Node;
		newNode->data = i+1;
		if (i != 8) {
			newNode->next = nullptr;
		}
		else {
			newNode->next = head;
		}
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNode;
	}
}

int LinkedList::findMiddle()
{
	Node* current = head;
	int middle = size / 2 ;
	for (int i = 0; i < middle; i++) {
		current = current->next;
	}
	return current->data;
}

int LinkedList::findMiddleHare()
{
	Node* slow = head;
	Node* fast = head;
	while (fast != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow->data;
}

void LinkedList::reverse()
{
	Node* current = head;
	Node* next = nullptr;
	Node* prev = nullptr;
	while (current != nullptr) {
		next = current->next;
		current->next = prev;
		prev = current;

		current = next;
	}
	head = prev;
}

Node* LinkedList::returnHead()
{
	if(head != nullptr) return head;
	return nullptr;
}

LinkedList* LinkedList::mergeList(LinkedList &l1, LinkedList &l2)
{
	size_t size = l1.getSize() + l2.getSize();
	LinkedList* list = new LinkedList();
	Node* head1 = l1.returnHead();
	Node* head2 = l2.returnHead();

	Node* current = nullptr;
	current = head1;
	while (current != nullptr) {
		list->push_back(current->data);
		current = current->next;
	}
	current = head2;
	while (current != nullptr) {
		list->push_back(current->data);
		current = current->next;
	}
	return list;
}

void LinkedList::removeTheNthNodeFromEnd(int n)
{
	if (head == nullptr || n <= 0 || n >= size) {
		return;
	}

	Node* current = head;
	Node* prev = nullptr;
	for (int i = 0; i < size - n; ++i) {
		prev = current;
		current = current->next;
	}
	if (prev != nullptr)
		prev->next = current->next;
	else head = head->next;

	if(current != nullptr)
		delete current;

	size--;
	return;
}

void LinkedList::removeDuplicates()
{
	Node* current = head;

	while(current =)
}

LinkedList::~LinkedList() {
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
