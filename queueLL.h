#ifndef QUEUE_LINKED_LIST_H
#define QUEUE_LINKED_LIST_H

#include <iostream>
#include "Node.h"
using namespace std;

class QueueLinkedList {
private:
	Node* head;
	int size;
public:
	QueueLinkedList();
	~QueueLinkedList();

	void enqueueBeg(int value);
	int dequeueEnd();
	void enqueueEnd(int value);
	int dequeueBeg();
};

#endif // !QUEUE_LINKED_LIST_H
