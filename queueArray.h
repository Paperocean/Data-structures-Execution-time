#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#include <iostream>
using namespace std;

class QueueArray {
private:
	int* arr;
	int size;
	int capacity;
	void resize(int new_capacity);
public:
	QueueArray();
	~QueueArray();

	void enqueueEnd(int value);
	int dequeueBeg();
	void enqueueBeg(int value);
	int dequeueEnd();
	int peek();
	bool isEmpty();
};

#endif // !QUEUE_ARRAY_H
