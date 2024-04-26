#ifndef LINKEDLISTMALLOC_H
#define LINKEDLISTMALLOC_H

#include <iostream>
#include <vector>
using namespace std;

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


#endif // LINKEDLISTMALLOC_H
