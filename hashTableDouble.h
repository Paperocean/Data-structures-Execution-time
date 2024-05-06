#ifndef HASHTABLE_DOUBLE_H
#define HASHTABLE_DOUBLE_H

#include <iostream>
using namespace std;

class HashTableDouble {
private:
	int* table;
	size_t size;
	size_t capacity;
	void resize(size_t newCapacity);
public:
	HashTableDouble(size_t capacity);
	~HashTableDouble();
	int hash(int key);
	int hash2(int key);
	void insert(int key, int value);
	void search(int key);
	void remove(int key);
	void display();
};

#endif