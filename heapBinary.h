#ifndef HEAP_BINARY_H
#define HEAP_BINARY_H

#include <iostream>
using namespace std;

class BinaryHeap {
private:
	int* heap;
	int size;
	int capacity;

	int parent(int index);
	int leftChild(int index);
	int rightChild(int index);

	void heapifyUp(int index);
	void maxHeapify(int size, int index);
	void resize(int newCapacity);

public:
	BinaryHeap();
	~BinaryHeap();
	void enqueue(int value);
	int dequeue();
	void display();
	void heapSort();
	bool binarySearch(int value);
};

#endif