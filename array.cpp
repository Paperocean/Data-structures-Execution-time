#include "array.h"

void Array::resize(int new_capacity) {
	int* new_arr = new int[new_capacity];
	for (size_t i = 0; i < size; i++) {
		new_arr[i] = arr[i];
	}
	delete[] arr;
	arr = new_arr;
	capacity = new_capacity;
}

Array::Array()
{
	arr = new int[16];
	size = 0;
	capacity = 16;
}

int Array::getSize() {
	return size;
}

void Array::push(int item) {
	if (size == capacity) {
		resize(capacity * 2);
	}
	arr[size++] = item;
}

int Array::pop() {
	if (size > 0) {
		int item = arr[size - 1];
		size--;
		return item;
	}
	else {
		cout << "Array is empty" << endl;
		return -1;
	}
}

Array::~Array() {
	delete[] arr;
}