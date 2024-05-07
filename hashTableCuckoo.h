#ifndef HASHTABLE_CUCKOO_H
#define HASHTABLE_CUCKOO_H

#include <iostream>
using namespace std;

class HashTableCuckoo {
private:
	int* table1;
	int* table2;
	int size;
	int capacity;
	int hash1(int key);
	int hash2(int key);
	void rehash();
public:
	HashTableCuckoo(int capacity);
	~HashTableCuckoo();
	void insert(int key, int value);
	void remove(int key);
	bool search(int key);
	void display();
};

#endif // HASHTABLE_CUCKOO_H