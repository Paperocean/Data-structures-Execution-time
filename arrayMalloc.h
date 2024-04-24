#ifndef ARRAY_MALLOC_H
#define ARRAY_MALLOC_H

#include <iostream>
using namespace std;

class ArrayMalloc {
private:
	int* arr;
	int size;
	int capacity;
	void resize(int new_capacity);
public:
	ArrayMalloc();
	int getSize();
	void push(int item);
	int pop();
	~ArrayMalloc();
};
#endif

