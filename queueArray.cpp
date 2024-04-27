#include "queueArray.h"

void QueueArray::resize(int new_capacity) {
	int* tempArray = new int[new_capacity];
	for (int i = 0; i < size; ++i) {
		tempArray[i] = arr[i];
	}
	delete[] arr;
	arr = tempArray;
	capacity = new_capacity;
}

QueueArray::QueueArray()
{
	capacity = 16;
	arr = new int[capacity];
	size = 0;
}

QueueArray::~QueueArray() {
	delete[] arr;
}

void QueueArray::enqueueEnd(int value) {
	if (size == capacity) {
		resize(capacity * 2);
	}
	arr[size++] = value;
}

int QueueArray::dequeueBeg() {
	if (size < 1) {
		cout << "Queue is empty" << endl;
		return -1;
	}
	int value = arr[0];
	for (int i = 1; i < size; ++i) {
		arr[i - 1] = arr[i];
	}
	if (size == capacity / 4)
		resize(capacity / 2);
	return value;
}

void QueueArray::enqueueBeg(int value) {
	size++;
	if (size == capacity) {
		resize(capacity * 2);
	}
	for (int i = 1; i < size; ++i) {
		arr[i] = arr[i-1];
	}
	arr[0] = value;
}

int QueueArray::dequeueEnd() {
	if (size < 1) {
		cout << "Queue is empty" << endl;
		return -1;
	}
	int value = arr[size-1];
	size--;
	if (size == capacity / 4)
		resize(capacity / 2);
	return value;
}