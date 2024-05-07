#include "hashTableCuckoo.h"

HashTableCuckoo::HashTableCuckoo(int capacity)
{
	this->capacity = capacity;
	this->size = 0;
	this->table1 = new int[capacity];
	this->table2 = new int[capacity];
	for (int i = 0; i < capacity; i++)
	{
		table1[i] = -1;
		table2[i] = -1;
	}
}

HashTableCuckoo::~HashTableCuckoo()
{
	delete[] table1;
	delete[] table2;
	capacity = 0;
	size = 0;
}

int HashTableCuckoo::hash1(int key)
{
	return key % capacity;
}

int HashTableCuckoo::hash2(int key)
{
	return 1 + (key % (capacity - 1));
}

void HashTableCuckoo::rehash(int newCapacity)
{
	int* oldTable1 = table1;
	int* oldTable2 = table2;
	int oldCapacity = capacity;

	size = 0;
	capacity = newCapacity;
	table1 = new int[capacity];
	table2 = new int[capacity];
	for (int i = 0; i < capacity; i++)
	{
		table1[i] = -1;
		table2[i] = -1;

	}
	for (int i = 0; i < oldCapacity; i++)
	{
		if (oldTable1[i] != -1)
		{
			insert(i, oldTable1[i]);
		}
		if (oldTable2[i] != -1)
		{
			insert(i, oldTable2[i]);
		}
	}
	delete[] oldTable1;
	delete[] oldTable2;
}

void HashTableCuckoo::insert(int key, int value) {
	int index = hash1(key);
	int* currentTable = table1;

	for (int i = 0; i < 10; i++) {
		if (currentTable[index] == -1) {
			currentTable[index] = value;
			size++;
			return;
		}

		std::swap(currentTable[index], value);

		if (currentTable == table1) {
			currentTable = table2;
			index = (index + hash2(key)) % capacity;
		}
		else {
			currentTable = table1;
			index = hash1(key);
		}
	}

	rehash(capacity * 2);
	insert(key, value);
}

void HashTableCuckoo::remove(int key) {
	int index = hash1(key);
	int* currentTable = table1;

	for(int i = 0; i < 10; i++) {
		if (currentTable[index] != -1) {
			currentTable[index] = -1;
			size--;
			return;
		}

		if (currentTable == table1) {
			currentTable = table2;
			index = (index + hash2(key)) % capacity;
		}
		else {
			currentTable = table1;
			index = (index + hash1(key)) % capacity;
		}
	}

	if (size <= capacity * 0.3) {
		rehash(capacity / 2);
		remove(key);
	}
	else {
		cout << "Key not found" << endl;
	}
}

bool HashTableCuckoo::search(int key) {
	int index = hash1(key);
	int* currentTable = table1;

	for(int i = 0; i < 10; i++) {
		if (currentTable[index] != -1) {
			return true;
		}

		if (currentTable == table1) {
			currentTable = table2;
			index = hash2(key);
		}
		else {
			currentTable = table1;
			index = hash1(key);
		}
	}
	return false;
}

void HashTableCuckoo::display() {
	cout << "Table 1: ";
	for (int i = 0; i < capacity; i++)
	{
		cout << table1[i] << " ";
	}
	cout << endl;

	cout << "Table 2: ";
	for (int i = 0; i < capacity; i++)
	{
		cout << table2[i] << " ";
	}
	cout << endl;
}
