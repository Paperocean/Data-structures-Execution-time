#ifndef NODE_H
#define NODE_H

#include <iostream>
struct Node {
	int data;
	Node* next;
	Node() : data(0), next(nullptr) {}
};

#endif // !NODE_H
