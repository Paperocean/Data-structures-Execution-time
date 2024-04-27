#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

#include <iostream>
#include "Node.h"
using namespace std;

class StackLinkedList {
private:
	Node* head;
	int size;
public:
	StackLinkedList();
	~StackLinkedList();

	void push(int values);
	int pop();

	void display();
};


#endif // !STACK_LINKED_LIST_H
