#include <iostream>
#include <chrono>
#include <vector>
#include "array.h"
#include "arrayMalloc.h"
using namespace std;

auto timeMeasureMallocArray(int value) {
	auto start = chrono::high_resolution_clock::now();
	for (size_t i = 0; i < 1000000; i++) {
		ArrayMalloc arr;
		for (size_t j = 0; j < value; j++) {
			arr.push(j);
		}
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	return duration / 1000000;
}

auto timeMeasureArray(int value) {
	auto start = chrono::high_resolution_clock::now();
	for (size_t i = 0; i < 1000000; i++) {
		Array arr;
		for (size_t j = 0; j < value; j++) {
			arr.push(j);
		}
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	return duration / 1000000;
}

auto timeMeasureVector(int value) {
	auto start = chrono::high_resolution_clock::now();
	for (size_t i = 0; i < 1000000; i++) {
		vector<int> arr;
		for (size_t j = 0; j < value; j++) {
			arr.push_back(j);
		}
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	return duration / 1000000;
}

int main()
{
	int count = 0;
	int highest = 0;

	for (int i = 0; i < 100; i++) {
		auto malArrayTime = timeMeasureMallocArray(i);
		auto arrayTime = timeMeasureArray(i);
		if (malArrayTime < arrayTime) {
			highest = i;
			cout << "I = " << highest << endl;
			cout << "Time taken by ArrayMalloc: " << timeMeasureMallocArray(i) << " ns" << endl;
			cout << "Time taken by Array: " << timeMeasureArray(i) << " ns" << endl;
			cout << endl;
			count = 0;
		}
		else count++;

		if (count == 5 and highest != 0) {
			cout << "The highest possible len of nums to add: " << highest;
			break;
		}
		//cout << "Time taken by Vector: " << timeMeasureVector(i) << " ns" << endl;
	}
}
