#include "hashTableLinear.h"

void HashTableLinear::resize(size_t newCapacity) {
	int* newTable = new int[newCapacity];
	for (size_t i = 0; i < newCapacity; i++) {
		newTable[i] = -1;
	}
	for (size_t i = 0; i < capacity; i++) {
		if (table[i] != -1) {
			int index = hash(i);
			while (newTable[index] != -1) {
				index = table[i] % newCapacity;
			}
			table[index] = table[i];
		}
	}
	delete[] table;
	table = newTable;
	capacity = newCapacity;
}

HashTableLinear::HashTableLinear(size_t capacity)
{
	this->capacity = capacity;
	table = new int[capacity];
	for (size_t i = 0; i < capacity; i++) {
		table[i] = -1;
	}
	size = 0;
}

HashTableLinear::~HashTableLinear()
{
	delete[] table;
	size = 0;
	capacity = 0;
}

int HashTableLinear::hash(int key)
{
	return key % capacity;
}

void HashTableLinear::insert(int key, int value)
{
	int index = hash(key);
	while (table[index] != -1) {
		index = (index + 1) % capacity;
	}
	table[index] = value;
	size++;
	if (size >= capacity) {
		resize(capacity * 2);
	}
}

int HashTableLinear::remove(int key) {
	int index = hash(key);
	while (table[index] != -1) {
		if (index == key) {
			int value = table[index];
			table[index] = -1;
			size--;
			return value;
		}
		index = (index + 1) % capacity;
	}
	if (size == capacity / 4)
		resize(capacity / 2);
}

void HashTableLinear::display()
{
	for (size_t i = 0; i < capacity; i++) {
		cout << i << ": ";
		if (table[i] != -1)
			cout << table[i];
		cout << endl;
	}
	cout << endl;
}

int HashTableLinear::search(int key) {
	int index = hash(key);
	int startIndex = index;
	do {
		if (index == key) {
			return table[index];
		}
		index = (index + 1) % capacity;
	} while (index != startIndex);
	return -1;
}
