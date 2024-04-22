#include "arrayMalloc.h"
using namespace std;

void ArrayMalloc::resize(int new_capacity){
	int* new_arr = static_cast<int*>(realloc(arr, new_capacity * sizeof(int)));
	if (new_arr) {
		arr = new_arr;
		capacity = new_capacity;
	}
	else {
		cout << "Memory reallocation failed" << endl;
	}
}

ArrayMalloc::ArrayMalloc()
{
	arr = static_cast<int*>(malloc(16 * sizeof(int)));
	size = 0;
	capacity = 16;
}

int ArrayMalloc::getSize() {
	return size;
}

void ArrayMalloc::push(int item) {
	if (size == capacity) {
		resize(capacity * 2);
	}
	arr[size++] = item;
}

int ArrayMalloc::pop() {
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

ArrayMalloc::~ArrayMalloc() {
	free(arr);
}
