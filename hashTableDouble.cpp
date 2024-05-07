#include "hashTableDouble.h"

void HashTableDouble::resize(size_t newCapacity)
{
	int* oldTable = table;
	int oldCapacity = capacity;

	size = 0;
	capacity = newCapacity;
	table = new int[capacity];
	for (int i = 0; i < capacity; i++)
	{
		table[i] = -1;
	}
	for (int i = 0; i < oldCapacity; i++)
	{
		if (oldTable[i] != -1)
		{
			insert(i, oldTable[i]);
		}
	}
	delete[] oldTable;
}

HashTableDouble::HashTableDouble(size_t capacity)
{
	this->capacity = capacity;
	size = 0;
	table = new int[capacity];
	for (size_t i = 0; i < capacity; i++)
	{
		table[i] = -1;
	}
}

HashTableDouble::~HashTableDouble()
{
	delete[] table;
	capacity = 0;
	size = 0;
}

int HashTableDouble::hash(int key)
{
	return key % capacity;
}

int HashTableDouble::hash2(int key)
{
	return 1 + (key % (capacity - 1));
}

void HashTableDouble::insert(int key, int value) {
	int index = hash(key);
	while (table[index] != -1) {
		index = (index + hash2(index)) % capacity;
	}
	table[index] = value;
	size++;
	if (size >= capacity)
		resize(capacity * 2);
}

void HashTableDouble::search(int key)
{
	int index = hash(key);
	int startIndex = index;
	do {
		if(table[index] != -1)
			cout << table[index];
		index = (index + hash2(index)) % capacity;
	} while (index != startIndex);
}

void HashTableDouble::remove(int key)
{
	int index = hash(key);
	while (table[index] != -1) {
		index = (index + hash2(index)) % capacity;
	}
	table[index] = -1;
	size--;
	if (size == capacity / 4)
		resize(capacity / 2);
}

void HashTableDouble::display() {
	for (size_t i = 0; i < capacity; i++) {
		cout << i << ": ";
		if (table[i] != -1)
			cout << table[i];
		cout << endl;
	}
	cout << endl;
}

