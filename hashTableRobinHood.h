#ifndef HASHTABLE_ROBINHOOD_H
#define HASHTABLE_ROBINHOOD_H

#include <iostream>
using namespace std;

class HashTableRobinHood{
private:
	int* table;
	size_t capacity;
	size_t size;
	void rehash(size_t newCapacity);
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
