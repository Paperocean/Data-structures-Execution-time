#ifndef HASHTABLE_CHAINING_H
#define HASHTABLE_CHAINING_H

#include <iostream>
using namespace std;

struct Node {
	int key;
	int value;
	Node* next;
};

class HashTableChaining {
private:
	Node** table;
	size_t size;
	size_t capacity;
	void resize(int newCapacity);
public:
	HashTableChaining(int capacity);
	~HashTableChaining();
	int hash(int key);
	void insert(int key, int value);
	int search(int key);
	int remove(int key);
	void display();
};

#endif // !HASHTABLE_CHAINING_H