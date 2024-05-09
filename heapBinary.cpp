#include "heapBinary.h"

int BinaryHeap::parent(int index)
{
    return (index - 1) / 2;
}

int BinaryHeap::leftChild(int index)
{
    return 2*index + 1;
}

int BinaryHeap::rightChild(int index)
{
    return 2*index + 2;
}

void BinaryHeap::heapifyUp(int index)
{
    while (index > 0 && heap[index] > heap[parent(index)]) {
        swap(heap[index], heap[parent(index)]);
        index = parent(index);
    }
}

void BinaryHeap::maxHeapify(int size, int index)
{
    int maxIndex = index;
    int left = leftChild(index);
    int right = rightChild(index);

    if (index < 0) return;

    if (right < size && heap[right] > heap[maxIndex]) {
        maxIndex = right;
    }
    if (left < size && heap[left] > heap[maxIndex]) {
        maxIndex = left;
    }

    if (maxIndex != index) {
        swap(heap[maxIndex], heap[index]);
        maxHeapify(size, maxIndex);
    }
}

void BinaryHeap::resize(int newCapacity)
{
}

BinaryHeap::BinaryHeap()
{
    size = 0;
    capacity = 16;
    heap = new int[capacity];
}

BinaryHeap::~BinaryHeap()
{
    delete[] heap;
}

void BinaryHeap::enqueue(int value)
{
    heap[size++] = value;
    heapifyUp(size - 1);
}

int BinaryHeap::dequeue()
{
    int value = heap[0];
    heap[0] = heap[--size];
    maxHeapify(size, 0);
    return value;
}

void BinaryHeap::display()
{
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

void BinaryHeap::heapSort()
{
    int n = size;
    for (int i = n - 1; i >= 0; i--) {
        swap(heap[0], heap[i]);
        maxHeapify(i, 0);
    }
}

bool BinaryHeap::binarySearch(int value)
{
    heapSort();
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (heap[mid] == value) {
            return true;
        }

        if (heap[mid] < value) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return false;
}
