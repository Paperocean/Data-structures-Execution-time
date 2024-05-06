#ifndef HASHTABLE_ROBINHOOD_H
#define HASHTABLE_ROBINHOOD_H

#include <iostream>
using namespace std;

struct TableEntry {
	int key;
	int value;
	int distance;

	TableEntry() {
		key = -1;
		value = -1;
		distance = -1;
	}

	TableEntry(int key, int value, int distance) {
		this->key = key;
		this->value = value;
		this->distance = distance;
	}
};

class HashTableRobinHood{
private:
	TableEntry* table;
	size_t capacity;
	size_t size;
	void resize(size_t newCapacity);
public:
	HashTableRobinHood(size_t capacity);
	~HashTableRobinHood();
	int hash(int key);
	int hash2(int key);
	int probeDistance(int index);
	void insert(int key, int value);
	int search(int key);
	void remove(int key);
	void display();
};

#endif // !HASHTABLE_ROBINHOOD_H
