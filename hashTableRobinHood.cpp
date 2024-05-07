#include "hashTableRobinHood.h"

void HashTableRobinHood::rehash(size_t newCapacity)
{
	int* oldTable = table;
	int oldCapacity = capacity;

	size = 0;
	capacity = newCapacity;
	table = new int[capacity];
	for (int i = 0; i < capacity; i++) {
		table[i] = -1;
	}
	for (int i = 0; i < oldCapacity; i++) {
		if (oldTable[i] != -1) {
			insert(i, oldTable[i]);
		}
	}

	delete[] oldTable;
}

HashTableRobinHood::HashTableRobinHood(size_t capacity)
{
	this->capacity = capacity;
	size = 0;
	table = new int[capacity];
	for (int i = 0; i < capacity; i++) {
		table[i] = -1;
	}
}

HashTableRobinHood::~HashTableRobinHood()
{
	delete[] table;
	capacity = 0;
	size = 0;
}

int HashTableRobinHood::hash(int key)
{
	return key % capacity;
}

int HashTableRobinHood::hash2(int key)
{
	return 1 + (key % (capacity - 1));
}

int HashTableRobinHood::probeDistance(int index)
{
	return (index - hash(index) + capacity) % capacity;
}

void HashTableRobinHood::insert(int key, int value) {
    int index = hash(key);
    int distance = 0;

    for(int i = 0; i < 10; i++) {
		if (table[index] == -1) {
			table[index] = value;
			size++;
			return;
		}

        // Scatter - minimaize the distance frome the ideal position
        int currentDistance = probeDistance(index);
        if (currentDistance < distance) {
			std::swap(table[index], value);
            distance = currentDistance;
        }

		index = (index + hash2(key)) % capacity;
        distance++;
    }

	rehash(capacity * 2);
    insert(key, value);
}

int HashTableRobinHood::search(int key) {
	int index = hash(key);
	int distance = 0;

    for(int i = 0; i < 10; i++) {
        if (table[index] != -1) {
			return table[index];
		}

		int currentDistance = probeDistance(index);
        if (currentDistance < distance) {
			return -1;
		}

		index = (index + hash2(key)) % capacity;
		distance++;
	}

	return -1;
}

void HashTableRobinHood::remove(int key) {
	int index = hash(key);
	int distance = 0;

	for(int i = 0; i < 10; i++) {
        if (table[index] != -1) {
			table[index] = -1;
			size--;
			return;
		}

		int currentDistance = probeDistance(index);
		if (currentDistance < distance) {
			return;
		}

		index = (index + hash2(key)) % capacity;
		distance++;
	}

	if (size < capacity / 4) {
		rehash(capacity / 2);
	}
}

void HashTableRobinHood::display() {
	for (size_t i = 0; i < capacity; i++) {
		cout << i << ": ";
		if (table[i] != -1) {
			cout << i << " " << table[i];
		}
		cout << endl;
	}
}