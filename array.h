#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

class Array {
private:
	int* arr;
	int size;
	int capacity;
	void resize(int new_capacity);
public:
	Array();
	int getSize();
	void push(int item);
	int pop();
	~Array();
};

#endif // !ARRAY_H

