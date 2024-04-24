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
	void display();
	void remove_value(int);

	bool isCycle();
	void makeCycle();

	int findMiddle();
	int findMiddleHare();

	void reverse();

	Node* returnHead();
	LinkedList* mergeList(LinkedList &l1, LinkedList &l2);
	~LinkedList();
};

#endif // !LINKED_LIST_H

