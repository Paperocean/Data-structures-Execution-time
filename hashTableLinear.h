#ifndef HASHTABLE_LINEAR_H
#define HASHTABLE_LINEAR_H

#include <iostream>
using namespace std;

class HashTableLinear {
private:
	int* table;
	size_t size;
	size_t capacity;
	void resize(size_t newCapacity);
public:
	HashTableLinear(size_t capacity);
	~HashTableLinear();
	int hash(int key);
	void insert(int key, int value);
	int search(int key);
	int remove(int key);
	void display();
};

#endif