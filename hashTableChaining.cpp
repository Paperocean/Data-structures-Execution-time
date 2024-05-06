#include "hashTableChaining.h"

void HashTableChaining::resize(size_t newCapacity) {
	Node** newTable = new Node * [newCapacity];
	for (size_t i = 0; i < newCapacity; i++) {
		newTable[i] = NULL;
	}
	for (size_t i = 0; i < capacity; i++) {
		Node* current = table[i];
		while (current != nullptr) {
			Node* next = current->next;
			int index = current->key % newCapacity;
			if (newTable[index] == NULL) {
				newTable[index] = table[i];
				current->next = nullptr;
			}
			else {
				Node* temp = table[index];
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
	table = new Node * [capacity];
	for (size_t i = 0; i < capacity; i++) {
		table[i] = NULL;
	}
	size = 0;
}

HashTableChaining::~HashTableChaining() {
	Node* current = table[0];
	Node* next = nullptr;
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
	if (size >= capacity) {
		resize(capacity * 2);
	}
	int index = hash(key);
	Node* newNode = new Node;
	newNode->key = key;
	newNode->value = value;
	newNode->next = nullptr;
	if (table[index] == NULL) {
		table[index] = newNode;
	}
	else {
		Node* current = table[index];
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNode;
	}
	size++;
}

int HashTableChaining::search(int key) {
	int index = hash(key);
	if (table[index] == NULL) {
		return -1;
	}
	else {
		Node* current = table[index];
		while (current != nullptr) {
			if (current->key == key)
				return current->value;
			current = current->next;
		}
	}
}

int HashTableChaining::remove(int key) {
	if (size == capacity / 4)
		resize(capacity / 2);
	int index = hash(key);
	if (table[index] == NULL) {
		return -1;
	}
	else {
		Node* current = table[index];
		Node* prev = nullptr;
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
}

void HashTableChaining::display() {
	for (size_t i = 0; i < capacity; i++) {
		Node* current = table[i];
		cout << i << ": ";
		while (current != nullptr) {
			cout << " Key: " << current->key;
			if (current->value != NULL)
				cout << " Value: " << current->value;
			else cout << " Value: NULL";
			cout << endl;
			current = current->next;
		}
		cout << endl;
	}
	cout << endl;
}