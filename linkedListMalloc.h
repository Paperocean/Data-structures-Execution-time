#ifndef LINKED_LIST_MALLOC_H
#define LINKED_LIST_MALLOC_H

#include <iostream>
#include <vector>

struct Node {
	Node* next;
	int data;
};

class LinkedListMalloc {
private:
	Node* head;
	int size = 0;
public:
	LinkedListMalloc();
	~LinkedListMalloc();

	void push_front(int value);
	int pop_front();
};


#endif // LINKED_LIST_MALLOC_H
