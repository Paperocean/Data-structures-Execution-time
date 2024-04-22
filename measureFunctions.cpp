#include "measureFunctions.h"
#include <iostream>
#include <chrono>
#include <vector>
#include "array.h"
#include "arrayMalloc.h"
using namespace std;

auto pushTimeMeasureMallocArray(int value) {
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

auto pushTimeMeasureArray(int value) {
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

auto pushTimeMeasureVector(int value) {
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
