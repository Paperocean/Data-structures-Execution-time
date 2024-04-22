#include <iostream>
#include <chrono>
#include <vector>
#include <vector>
#include "array.h"
#include "arrayMalloc.h"
#include "linkedList.h"
using namespace std;

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

int main()
{
	// ARRAY
	/*int count = 0;
	int tries = 100;
	int highestTime[3] = {};

	for (int i = 0; i < tries; i++) {
		long long malArrayTime = pushTimeMeasureMallocArray(i);
		long long arrayTime = pushTimeMeasureArray(i);
		long long vectorTime = pushTimeMeasureVector(i);

		if (malArrayTime < arrayTime) {
			highestTime[0] = malArrayTime;
			highestTime[1] = arrayTime;
			if(vectorTime < malArrayTime)
				highestTime[2] = vectorTime;
			count = 0;
		}
		else count++;

		if (count == 5) {
			break;
		}
	}

	for(int i = 0; i < 3; i++)
		cout << highestTime[i] << endl;*/

	// LINKED LIST
	LinkedList list;
	for (int i = 0; i < 10; i++)
		list.push_front(i);
	list.display();

	cout << endl;

	list.reverse();
	list.display();
	getchar();
	return 0;
}
