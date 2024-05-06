#include "hashTableRobinHood.h"

HashTableRobinHood::HashTableRobinHood(size_t capacity)
{
	this->capacity = capacity;
	size = 0;
	table = new TableEntry[capacity];
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
	return (index - hash(table[index].key) + capacity) % capacity;
}

void HashTableRobinHood::insert(int key, int value) {
    int index = hash(key);
    int distance = 0;

    while (table[index].key != -1) {
        if (table[index].key == key) {
            table[index].value = value;
            return;
        }
        
        // Rozproszenie
        int currentDistance = probeDistance(index);
        if (currentDistance < distance) {
            std::swap(table[index].key, key);
            std::swap(table[index].value, value);
            distance = currentDistance;
        }

        index = (index + hash2(key)) % capacity;
        distance++;
    }

    table[index].key = key;
    table[index].value = value;
    size++;
}

int HashTableRobinHood::search(int key) {
	int index = hash(key);
	int distance = 0;

    while (table[index].key != -1) {
        if (table[index].key == key) {
			return table[index].value;
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

    while (table[index].key != -1) {
        if (table[index].key == key) {
			table[index].key = -1;
			table[index].value = -1;
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
}

void HashTableRobinHood::display() {
	for (size_t i = 0; i < capacity; i++) {
		std::cout << i << ": ";
		if (table[i].key != -1) {
			std::cout << table[i].key << " " << table[i].value << " " << table[i].distance;
		}
		std::cout << std::endl;
	}
}