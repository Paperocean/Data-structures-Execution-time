#include "stackA.h"

void StackArray::resize(int new_capacity)
{
	int* tempArray = new int[new_capacity];
	for (int i = 0; i < size; i++) {
		tempArray[i] = arr[i];
	}
	delete[] arr;
	arr = tempArray;
	capacity = new_capacity;
}

StackArray::StackArray()
{
	capacity = 16;
	arr = new int[capacity];
	size = 0;
}

StackArray::~StackArray() {
	delete[] arr;
}

void StackArray::push(int value) {
	if (size == capacity) {
		resize(capacity * 2);
	}
	arr[size++] = value;
}

int StackArray::pop()
{
	int value = -1;
	if (size > 0) {
		value = arr[size - 1];
		size--;
		if (size == capacity / 4)
			resize(capacity / 2);
	}
	return value;
}
