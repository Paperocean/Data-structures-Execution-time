#include "hashTableQuadric.h"

void HashTableQuadric::resize(size_t newCapacity)
{
	int* newTable = new int[newCapacity];
	for (size_t i = 0; i < newCapacity; i++) {
		newTable[i] = -1;
	}
	for (size_t i = 0; i < capacity; i++) {
		if (table[i] != -1) {
			int index = hash(i);
			while (newTable[index] != -1) {
				index = (index * 2) % newCapacity;
			}
			newTable[index] = table[index];
		}
	}
	delete[] table;
	table = newTable;
	capacity = newCapacity;
}

HashTableQuadric::HashTableQuadric(size_t capacity)
{
	this->capacity = capacity;
	table = new int[capacity];
	for (size_t i = 0; i < capacity; i++) {
		table[i] = -1;
	}
	size = 0;
}

HashTableQuadric::~HashTableQuadric()
{
	delete[] table;
	size = 0;
	capacity = 0;
}

int HashTableQuadric::hash(int key)
{
	return key % capacity;
}

void HashTableQuadric::insert(int key, int value)
{
	int index = hash(key);
	while (table[index] != -1) {
		index = (index * 2) % capacity;
	}
	table[index] = value;
	size++;
	if (size >= capacity) {
		resize(capacity * 2);
	}
}

void HashTableQuadric::remove(int key)
{
	int index = hash(key);
	while (table[index] != -1) {
		int value = table[index];
		table[index] = -1;
		size--;
		index = (index * 2) % capacity;
	}
	if (size == capacity / 4)
		resize(capacity / 2);
}

int HashTableQuadric::search(int key) {
	int index = hash(key);
	int startIndex = index;
	do{
		if (table[index] != -1) {
			return table[index];
		}
	} while (index != startIndex);
	return -1;
}

void HashTableQuadric::display()
{
	for (size_t i = 0; i < capacity; i++) {
		cout << i << ": ";
		if (table[i] != -1) {
			cout << table[i];
		}
		cout << endl;
	}
	cout << endl;
}
