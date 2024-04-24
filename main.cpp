#include <iostream>
#include <chrono>
#include <vector>
#include "array.h"
#include "arrayMalloc.h"
#include "linkedList.h"
using namespace std;

// ARRAY
long long pushTimeMeasureMallocArray(int value) {
	auto start = chrono::high_resolution_clock::now();
	for (size_t i = 0; i < 1000000; i++) {
		ArrayMalloc arr;
		for (size_t j = 0; j < value; j++) {
			arr.push(j);
		}
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
	return duration.count() / 1000000;
}
long long pushTimeMeasureArray(int value) {
	auto start = chrono::high_resolution_clock::now();
	for (size_t i = 0; i < 1000000; i++) {
		Array arr;
		for (size_t j = 0; j < value; j++) {
			arr.push(j);
		}
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
	return duration.count() / 1000000;
}
long long pushTimeMeasureVector(int value) {
	auto start = chrono::high_resolution_clock::now();
	for (size_t i = 0; i < 1000000; i++) {
		vector<int> arr;
		for (size_t j = 0; j < value; j++) {
			arr.push_back(j);
		}
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
	return duration.count() / 1000000;
}

// LINKED LIST
long long pushFTimeMeasureLinkedList(int value) {
	auto start = chrono::high_resolution_clock::now();
	for (size_t i = 0; i < 1000000; i++) {
		LinkedList list;
		for (size_t j = 0; j < value; j++) {
			list.push_front(j);
		}
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
	return duration.count() / 1000000;
}
long long pushBTimeMeasureLinkedList(int value) {
	auto start = chrono::high_resolution_clock::now();
	for (size_t i = 0; i < 1000000; i++) {
		LinkedList list;
		for (size_t j = 0; j < value; j++) {
			list.push_back(j);
		}
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
	return duration.count() / 1000000;
}
long long findMiddleTimeMeasureLinkedList(int value) {
	auto start = chrono::high_resolution_clock::now();
	for (size_t i = 0; i < 1000000; i++) {
		LinkedList list;
		for (size_t j = 0; j < value; j++) {
			list.push_back(j);
		}
		list.findMiddle();
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
	return duration.count() / 1000000;
}
long long findMiddleHareTimeMeasureLinkedList(int value) {
	auto start = chrono::high_resolution_clock::now();
	for (size_t i = 0; i < 1000000; i++) {
		LinkedList list;
		for (size_t j = 0; j < value; j++) {
			list.push_back(j);
		}
		list.findMiddleHare();
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
	return duration.count() / 1000000;
}
int main()
{
	// ARRAY
	/*Array arr;
	for (int i = 0; i < 10; i++)
		arr.push(i);
	arr.display();

	cout << endl;*/

	// LINKED LIST
	LinkedList list1, list2;
	for (int i = 1; i < 10; i++) {
		list1.push_back(i);
		list2.push_back(i + 9);
	}

	LinkedList* list = new LinkedList;

	list->mergeList(list1, list2);
	list->display();

	/*list.display();
	list.reverse();
	list.display();*/

	/*list.makeCycle();
	cout << "CYCLE: " << boolalpha << list.isCycle() << endl;*/
	//list.display();

	// TESTING TIMES
	/*int count = 0;
	int tries = 100;
	int highestTime[4] = {};

	for (int i = 0; i < tries; i++) {
		long long malArrayTime = pushTimeMeasureMallocArray(i);
		long long arrayTime = pushTimeMeasureArray(i);
		long long vectorTime = pushTimeMeasureVector(i);
		long long linkedListFTime = pushFTimeMeasureLinkedList(i);
		long long linkedListBTime = pushBTimeMeasureLinkedList(i);

		if (malArrayTime < arrayTime || linkedListFTime < malArrayTime) {
			highestTime[0] = malArrayTime;
			highestTime[1] = arrayTime;
			highestTime[3] = linkedListFTime;
			if(vectorTime < malArrayTime)
				highestTime[2] = vectorTime;
			count = 0;
		}
		else count++;

		if (count == 10) {
			break;
		}
	}

	int highestTimeSize = sizeof(highestTime) / sizeof(highestTime[0]);
	for (int i = 0; i < highestTimeSize; i++) {
		if(i == 0)
			cout << "ArrayMalloc: ";
		else if (i == 1)
			cout << "Array: ";
		else if (i == 2)
			cout << "Vector: ";
		else if (i == 3)
			cout << "LinkedListF: ";
		else
			cout << "Unknown: ";
		cout << highestTime[i] << endl;
	}*/
	
	// Testing middle find linked lists
	/*long long findMiddle = findMiddleTimeMeasureLinkedList(100);
	long long arrayTime = findMiddleHareTimeMeasureLinkedList(100);

	cout << "Find Middle: " << findMiddle << endl;
	cout << "Find Middle Hare: " << arrayTime << endl;*/

	getchar();
	return 0;
}
