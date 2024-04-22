#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

/*
Implement a vector (mutable array with automatic resizing):
 Practice coding using arrays and pointers, and pointer math to jump to an index instead of using indexing.
 New raw data array with allocated memory
can allocate int array under the hood, just not use its features
start with 16, or if the starting number is greater, use power of 2 - 16, 32, 64, 128
 size() - number of items
 capacity() - number of items it can hold
 is_empty()
 at(index) - returns the item at a given index, blows up if index out of bounds
 push(item)
 insert(index, item) - inserts item at index, shifts that index's value and trailing elements to the right
 prepend(item) - can use insert above at index 0
 pop() - remove from end, return value
 delete(index) - delete item at index, shifting all trailing elements left
 remove(item) - looks for value and removes index holding it (even if in multiple places)
 find(item) - looks for value and returns first index with that value, -1 if not found
 resize(new_capacity) // private function
when you reach capacity, resize to double the size
when popping an item, if the size is 1/4 of capacity, resize to half
 Time
O(1) to add/remove at end (amortized for allocations for more space), index, or update
O(n) to insert/remove elsewhere
*/

class ArrayMalloc {
private:
	int* arr;
	int size;
	int capacity;

	void resize(int new_capacity) {
		int* new_arr = static_cast<int*>(realloc(arr, new_capacity * sizeof(int)));
		if (new_arr) {
			arr = new_arr;
			capacity = new_capacity;
		}
		else {
			cout << "Memory reallocation failed" << endl;
		}
	}

public:
	ArrayMalloc() {
		arr = static_cast<int*>(malloc(16 * sizeof(int)));
		size = 0;
		capacity = 16;
	}

	int getSize() {
		return size;
	}

	void push(int item) {
		if (size == capacity) {
			resize(capacity * 2);
		}
		arr[size++] = item;
	}

	int pop() {
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

	~ArrayMalloc() {
		free(arr);
	}
};
class Array {
private:
	int* arr;
	int size;
	int capacity;

	void resize(int new_capacity) {
		int* new_arr = static_cast<int*>(realloc(arr, new_capacity * sizeof(int)));
		if (new_arr) {
			arr = new_arr;
			capacity = new_capacity;
		}
		else {
			cout << "Memory reallocation failed" << endl;
		}
	}

public:
	Array() {
		arr = new int[16];
		size = 0;
		capacity = 16;
	}

	int getSize() {
		return size;
	}

	void push(int item) {
		if (size == capacity) {
			resize(capacity * 2);
		}
	}

	int pop() {
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

	~Array() {
		delete[] arr;
	}
};

auto timeMeasureMallocArray() {
	auto start = chrono::high_resolution_clock::now();
	for (size_t i = 0; i < 1000000; i++) {
		ArrayMalloc arr;
		for (size_t j = 0; j < 1000; j++) {
			arr.push(j);
		}
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	return duration / 1000000;
}

auto timeMeasureArray() {
	auto start = chrono::high_resolution_clock::now();
	for (size_t i = 0; i < 1000000; i++) {
		Array arr;
		for (size_t j = 0; j < 1000; j++) {
			arr.push(j);
		}
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	return duration / 1000000;
}

auto timeMeasureVector() {
	auto start = chrono::high_resolution_clock::now();
	for (size_t i = 0; i < 1000000; i++) {
		vector<int> arr;
		for (size_t j = 0; j < 1000; j++) {
			arr.push_back(j);
		}
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	return duration / 1000000;
}

int main()
{
	cout << "Time taken by ArrayMalloc: " << timeMeasureMallocArray() << " ns" << endl;
	cout << "Time taken by Array: " << timeMeasureArray() << " ns" << endl;
	cout << "Time taken by Vector: " << timeMeasureVector() << " ns" << endl;
}
