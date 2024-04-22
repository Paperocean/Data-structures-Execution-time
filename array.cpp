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

Array::Array() {
	capacity = 16;
	arr = new int[capacity];
	size = 0;
	if (arr == nullptr)
	{
		cout << "Memory allocation failed" << endl;
	}
}

Array::Array(int len)
{
	capacity = 16;
	while (len > capacity) {
		len *= 2;
		capacity = len;
	}
	arr = new int[capacity];
	size = 0;
	if (arr == nullptr)
	{
		cout << "Memory allocation failed" << endl;
	}
}

int Array::get_size() {
	return size;
}

int Array::get_capacity() {
	return capacity;
}

bool Array::is_empty() {
	return size == 0;
}

int Array::at(int index) { // getter
	if (index < size) {
		return arr[index];
	}
}

void Array::push(int item) {
	if (capacity == size) {
		resize(capacity * 2);
	}
	arr[size++] = item;
}

void Array::insert(int index, int item) {
	if (index == size) {
		push(item);
	}
	else {
		if (capacity == size) {
			resize(capacity * 2);
		}
		for (int i = size; i > index; i--) {
			arr[i] = arr[i - 1];
		}
		arr[index] = item;
		size++;
	}
}

void Array::prepend(int item) {
	insert(0, item);
}

int Array::pop() {
	if (size > 0) {
		int item = arr[size - 1];
		size--;
		if (size == capacity / 4) {
			resize(capacity / 2);
		}
		return item;
	}
	return -1;
}

void Array::delete_item(int index) {
	if (index < size) {
		for (size_t i = index; i < size - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		size--;
		if (size == capacity / 4) {
			resize(capacity / 2);
		}
	}
}

void Array::remove(int item) {
	if (size > 0) {
		for (size_t i = 0; i < size; i++)
		{
			if (arr[i] == item) {
				delete_item(i);
			}
		}
	}
}

int Array::find(int item) {
	if (size > 0) {
		for (size_t i = 0; i < size; i++) {
			if (item == arr[i])
				return i;
		}
	}
	return -1;
}

void Array::display() {
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

Array::~Array() {
	delete[] arr;
}