#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
using namespace std;

class BinarySearchTree {
private:
	struct Node {
		int data;
		Node* left;
		Node* right;
	};

	Node* root;
	int size;

	/*
	I dont understand how the remove function works, also the succesor and predecessor functions...
	*/

	void display(Node* current);
	bool search(Node* current, int value);
	int getHeight(Node* current);
	int getSuccessor(Node* current);
	int getPredecessor(Node* current);

public:
	BinarySearchTree();
	~BinarySearchTree();
	void insert(int value);
	void remove(int value);
	bool search(int value);
	void display();
	int getSize();
	int getHeight();
	int getSuccessor(int value);
	int getPredecessor(int value);
};

#endif