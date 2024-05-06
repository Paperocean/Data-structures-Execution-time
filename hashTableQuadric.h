#ifndef HASHTABLE_QUADRIC_H
#define HASHTABLE_QUADRIC_H

#include <iostream>
using namespace std;

class HashTableQuadric {
private:
	int* table;
	size_t size;
	size_t capacity;
	void resize(size_t newCapacity);
public:
	HashTableQuadric(size_t capacity);
	~HashTableQuadric();
	int hash(int key);
	void insert(int key, int value);
	void remove(int key);
	int search(int key);
	void display();
};

#endif