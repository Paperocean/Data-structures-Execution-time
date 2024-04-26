#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <iostream>
using namespace std;

class StackArray {
private:
	int* arr;
	int size;
	int capacity;

	void resize(int new_capacity);
public:
	StackArray();
	~StackArray();

	void push(int value);
	int pop();
};

#endif // !STACK_ARRAY_H