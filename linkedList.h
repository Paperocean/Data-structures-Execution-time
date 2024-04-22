#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

struct Node {
	Node* next;
	int data;
};

class LinkedList {
private:
	Node* head;
	int size;
public:
	LinkedList();
	int getSize();
	bool isEmpty();
	int value_at(int);
	void push_front(int);
	int pop_front();
	void push_back(int);
	int pop_back();
	int getFront();
	int getBack();
	void insert(int, int);
	void erase(int);
	int value_n_from_end(int);
	void reverse();
	void display();
	void remove_value(int);
	~LinkedList();
};

#endif // !LINKED_LIST_H

