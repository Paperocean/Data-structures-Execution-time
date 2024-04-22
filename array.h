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
	Array(int len);
	int get_size();
	int get_capacity();
	bool is_empty();
	int at(int index);
	void push(int item);
	void insert(int index, int item);
	void prepend(int item);
	int pop();
	void delete_item(int index);
	void remove(int item);
	int find(int item);
	void display();
	~Array();
};

#endif // !ARRAY_H

