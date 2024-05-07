#include "hashTableChaining.h"

void HashTableChaining::resize(size_t newCapacity) {
	NodeHT** newTable = new NodeHT * [newCapacity];
	for (size_t i = 0; i < newCapacity; i++) {
		newTable[i] = NULL;
	}
	for (size_t i = 0; i < capacity; i++) {
		NodeHT* current = table[i];
		while (current != nullptr) {
			NodeHT* next = current->next;
			int index = current->key % newCapacity;
			if (newTable[index] == NULL) {
				newTable[index] = table[i];
				current->next = nullptr;
			}
			else {
				NodeHT* temp = table[index];
				while (temp->next != nullptr) {
					temp = temp->next;
				}
				temp->next = newTable[i];
				current->next = nullptr;
			}
			current = next;
		}
	}
	delete[] table;
	table = newTable;
	capacity = newCapacity;
}

HashTableChaining::HashTableChaining(int capacity) {
	this->capacity = capacity;
	table = new NodeHT * [capacity];
	for (size_t i = 0; i < capacity; i++) {
		table[i] = NULL;
	}
	size = 0;
}

HashTableChaining::~HashTableChaining() {
	NodeHT* current = table[0];
	NodeHT* next = nullptr;
	while (current != nullptr) {
		next = current->next;
		delete current;
		current = next;
	}
	delete[] table;
	size = 0;
	capacity = 0;
}

int HashTableChaining::hash(int key) {
	return key % capacity;
}

void HashTableChaining::insert(int key, int value) {
	int index = hash(key);
	NodeHT* newNodeHT = new NodeHT;
	newNodeHT->key = key;
	newNodeHT->value = value;
	newNodeHT->next = nullptr;
	if (table[index] == NULL) {
		table[index] = newNodeHT;
	}
	else {
		NodeHT* current = table[index];
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNodeHT;
	}
	size++;

	if (size >= capacity) {
		resize(capacity * 2);
	}
}

int HashTableChaining::search(int key) {
	int index = hash(key);
	if (table[index] == NULL) {
		return -1;
	}
	else {
		NodeHT* current = table[index];
		while (current != nullptr) {
			if (current->key == key)
				return current->value;
			current = current->next;
		}
	}
}

int HashTableChaining::remove(int key) {
	int index = hash(key);
	if (table[index] == NULL) {
		return -1;
	}
	else {
		NodeHT* current = table[index];
		NodeHT* prev = nullptr;
		while (current != nullptr) {
			if (current->key == key) {
				int value = current->value;
				if (prev == nullptr)
					table[index] = current->next;
				else
					prev->next = current->next;
				delete current;
				return value;
			}
			prev = current;
			current = current->next;
		}
	}

	if (size == capacity / 4)
		resize(capacity / 2);
}

void HashTableChaining::display() {
	for (size_t i = 0; i < capacity; i++) {
		NodeHT* current = table[i];
		cout << "Key: " << i << ": ";
		while (current != nullptr) {
			if (current->value != NULL)
				cout << " Value: " << current->value;
			else cout << " Value: NULL";
			current = current->next;
		}
		cout << endl;
	}
	cout << endl;
}