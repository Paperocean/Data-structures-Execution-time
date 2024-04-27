#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <vector>
#include "Node.h"

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
	void mergeList(LinkedList &l1, LinkedList &l2);
	void removeTheNthNodeFromEnd(int n);
	void removeDuplicates();
	bool isEqual(LinkedList& list2);
	bool isPalindrome();
	int getMaxNum();
	~LinkedList();
};

#endif // !LINKED_LIST_H

