#include <iostream>
#include <chrono>
#include <vector>
#include <map>
#include <functional>

#include "array.h"
#include "arrayMalloc.h"
#include "linkedList.h"
#include "stackA.h"
#include "stackLinkedL.h"
#include "queueArray.h"
#include "queueLL.h"
#include "hashTableChaining.h"
#include "hashTableLinear.h"
#include "hashTableRobinHood.h"
#include "hashTableDouble.h"
#include "hashTableQuadric.h"


using namespace std;

// ARRAY
//long long pushTimeMeasureMallocArray(int value) {
//	auto start = chrono::high_resolution_clock::now();
//	for (size_t i = 0; i < 1000000; i++) {
//		ArrayMalloc arr;
//		for (size_t j = 0; j < value; j++) {
//			arr.push(j);
//		}
//	}
//	auto end = chrono::high_resolution_clock::now();
//	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
//	return duration.count() / 1000000;
//}
//long long pushTimeMeasureArray(int value) {
//	auto start = chrono::high_resolution_clock::now();
//	for (size_t i = 0; i < 1000000; i++) {
//		Array arr;
//		for (size_t j = 0; j < value; j++) {
//			arr.push(j);
//		}
//	}
//	auto end = chrono::high_resolution_clock::now();
//	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
//	return duration.count() / 1000000;
//}
//long long pushTimeMeasureVector(int value) {
//	auto start = chrono::high_resolution_clock::now();
//	for (size_t i = 0; i < 1000000; i++) {
//		vector<int> arr;
//		for (size_t j = 0; j < value; j++) {
//			arr.push_back(j);
//		}
//	}
//	auto end = chrono::high_resolution_clock::now();
//	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
//	return duration.count() / 1000000;
//}

// LINKED LIST
//long long pushFTimeMeasureLinkedList(int value) {
//	auto start = chrono::high_resolution_clock::now();
//	for (size_t i = 0; i < 1000000; i++) {
//		LinkedList list;
//		for (size_t j = 0; j < value; j++) {
//			list.push_front(j);
//		}
//	}
//	auto end = chrono::high_resolution_clock::now();
//	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
//	return duration.count() / 1000000;
//}
//long long pushBTimeMeasureLinkedList(int value) {
//	auto start = chrono::high_resolution_clock::now();
//	for (size_t i = 0; i < 1000000; i++) {
//		LinkedList list;
//		for (size_t j = 0; j < value; j++) {
//			list.push_back(j);
//		}
//	}
//	auto end = chrono::high_resolution_clock::now();
//	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
//	return duration.count() / 1000000;
//}
//long long findMiddleTimeMeasureLinkedList(int value) {
//	auto start = chrono::high_resolution_clock::now();
//	for (size_t i = 0; i < 1000000; i++) {
//		LinkedList list;
//		for (size_t j = 0; j < value; j++) {
//			list.push_back(j);
//		}
//		list.findMiddle();
//	}
//	auto end = chrono::high_resolution_clock::now();
//	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
//	return duration.count() / 1000000;
//}
//long long findMiddleHareTimeMeasureLinkedList(int value) {
//	auto start = chrono::high_resolution_clock::now();
//	for (size_t i = 0; i < 1000000; i++) {
//		LinkedList list;
//		for (size_t j = 0; j < value; j++) {
//			list.push_back(j);
//		}
//		list.findMiddleHare();
//	}
//	auto end = chrono::high_resolution_clock::now();
//	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
//	return duration.count() / 1000000;
//}

// STACK
//long long pushStackArray(int value) {
//	auto start = chrono::high_resolution_clock::now();
//	for (size_t i = 0; i < 1000000; i++) {
//		StackArray arr;
//		for (size_t j = 0; j < value; j++) {
//			arr.push(j);
//		}
//	}
//	auto end = chrono::high_resolution_clock::now();
//	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
//	return duration.count() / 1000000;
//}
//long long pushStackLinkedList(int value) {
//	auto start = chrono::high_resolution_clock::now();
//	for (size_t i = 0; i < 1000000; i++) {
//		StackLinkedList list;
//		for (size_t j = 0; j < value; j++) {
//			list.push(j);
//		}
//	}
//	auto end = chrono::high_resolution_clock::now();
//	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
//	return duration.count() / 1000000;
//}
//long long popStackArray(int value) {
//	auto start = chrono::high_resolution_clock::now();
//	for (size_t i = 0; i < 1000000; i++) {
//		StackArray arr;
//
//		for (size_t j = 0; j < value; j++) {
//			arr.push(j);
//		}
//		for (size_t j = 0; j < value; j++) {
//			arr.pop();
//		}
//	}
//	auto end = chrono::high_resolution_clock::now();
//	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
//	return duration.count() / 1000000;
//}
//long long popStackLinkedList(int value) {
//	auto start = chrono::high_resolution_clock::now();
//	for (size_t i = 0; i < 1000000; i++) {
//		StackLinkedList list;
//		for (size_t j = 0; j < value; j++) {
//			list.push(j);
//		}
//		for (size_t j = 0; j < value; j++) {
//			list.pop();
//		}
//	}
//	auto end = chrono::high_resolution_clock::now();
//	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
//	return duration.count() / 1000000;
//}

// QUEUE
//long long pushQueueArrayEnd(int value) {
//	auto start = chrono::high_resolution_clock::now();
//	for (size_t i = 0; i < 1000000; i++) {
//		QueueArray arr;
//		for (size_t j = 0; j < value; j++) {
//			arr.enqueueEnd(j);
//		}
//	}
//	auto end = chrono::high_resolution_clock::now();
//	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
//	return duration.count() / 1000000;
//}
//long long pushQueueArrayBeg(int value) {
//	auto start = chrono::high_resolution_clock::now();
//	for (size_t i = 0; i < 1000000; i++) {
//		QueueArray arr;
//		for (size_t j = 0; j < value; j++) {
//			arr.enqueueBeg(j);
//		}
//	}
//	auto end = chrono::high_resolution_clock::now();
//	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
//	return duration.count() / 1000000;
//}
//long long popQueueArrayBeg(int value) {
//	auto start = chrono::high_resolution_clock::now();
//	for (size_t i = 0; i < 1000000; i++) {
//		QueueArray arr;
//		for (size_t j = 0; j < value; j++) {
//			arr.enqueueEnd(j);
//		}
//		for (size_t j = 0; j < value; j++) {
//			arr.dequeueBeg();
//		}
//	}
//	auto end = chrono::high_resolution_clock::now();
//	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
//	return duration.count() / 1000000;
//}
//long long popQueueArrayEnd(int value) {
//	auto start = chrono::high_resolution_clock::now();
//	for (size_t i = 0; i < 1000000; i++) {
//		QueueArray arr;
//		for (size_t j = 0; j < value; j++) {
//			arr.enqueueBeg(j);
//		}
//		for (size_t j = 0; j < value; j++) {
//			arr.dequeueEnd();
//		}
//	}
//	auto end = chrono::high_resolution_clock::now();
//	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
//	return duration.count() / 1000000;
//}

// QUEUE ARRAY
long long pushTimeMeasureQueueArray(function<void(QueueArray&, int)> operation, int value) {
	auto start = chrono::high_resolution_clock::now();
	for (size_t i = 0; i < 1000000; i++) {
		QueueArray arr;
		for (int j = 0; j < value; j++) {
			operation(arr, j);
		}
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
	return duration.count() / 1000000;
}
// POPING
long long popBegTimeMeasureQueueArray(int value) {
	auto start = chrono::high_resolution_clock::now();
	for (size_t i = 0; i < 1000000; i++) {
		QueueArray arr;
		for (int j = 0; j < value; j++) {
			arr.enqueueEnd(j);
		}
		for (int j = 0; j < value; j++) {
			arr.dequeueBeg();
		}
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
	return duration.count() / 1000000;
}
long long popEndTimeMeasureQueueArray(int value) {
	auto start = chrono::high_resolution_clock::now();
	for (size_t i = 0; i < 1000000; i++) {
		QueueArray arr;
		for (int j = 0; j < value; j++) {
			arr.enqueueBeg(j);
		}
		for (int j = 0; j < value; j++) {
			arr.dequeueEnd();
		}
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
	return duration.count() / 1000000;
}

// QUEUE LINKED LIST
long long timeMeasureQueueLinkedList(function<void(QueueLinkedList&, int)> operation, int value) {
	auto start = chrono::high_resolution_clock::now();
	for (size_t i = 0; i < 1000000; i++) {
		QueueLinkedList list;
		for (int j = 0; j < value; j++) {
			operation(list, j);
		}
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
	return duration.count() / 1000000;
}

// HASH TABLE
long long timeMeasureHashTableChaining(function<void(HashTableChaining&, int, int)> operation, int key, int value) {
	auto start = chrono::high_resolution_clock::now();
	for (size_t i = 0; i < 1000; i++) {
		HashTableChaining hashTab(20);
		for (int j = 0; j < value; j++) {
			operation(hashTab, key, j);
		}
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
	return duration.count() / 1000;
}

// HASH TABLE LINEAR
long long timeMeasureHashTableLinear(function<void(HashTableLinear&, int, int)> operation, int key, int value) {
	auto start = chrono::high_resolution_clock::now();
	for (size_t i = 0; i < 1000; i++) {
		HashTableLinear hashTab(20);
		for (int j = 0; j < value; j++) {
			operation(hashTab, key, j);
		}
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
	return duration.count() / 1000;
}

// HASH TABLE DOUBLE
long long timeMeasureHashTableDouble(function<void(HashTableDouble&, int, int)> operation, int key, int value) {
	auto start = chrono::high_resolution_clock::now();
	for (size_t i = 0; i < 1000; i++) {
		HashTableDouble hashTab(20);
		for (int j = 0; j < value; j++) {
			operation(hashTab, key, j);
		}
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
	return duration.count() / 1000;
}

// HASH TABLE QUADRIC
long long timeMeasureHashTableQuadric(function<void(HashTableQuadric&, int, int)> operation, int key, int value) {
	auto start = chrono::high_resolution_clock::now();
	for (size_t i = 0; i < 1000; i++) {
		HashTableQuadric hashTab(20);
		for (int j = 0; j < value; j++) {
			operation(hashTab, key, j);
		}
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
	return duration.count() / 1000;
}

// HASH TABLE ROBIN HOOD
long long timeMeasureHashTableRobinHood(function<void(HashTableRobinHood&, int, int)> operation, int key, int value) {
	auto start = chrono::high_resolution_clock::now();
	for (size_t i = 0; i < 1000; i++) {
		HashTableRobinHood hashTab(20);
		for (int j = 0; j < value; j++) {
			operation(hashTab, key, j);
		}
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
	return duration.count() / 1000;
}

int main()
{
	//map<string, long long> resultsHT;

	//for (int i = 0; i < 50; i++) {
	//	resultsHT["HashTableChaining"] += timeMeasureHashTableChaining([](HashTableChaining& hashTab, int key, int j) { hashTab.insert(key, j); }, i, 1);
	//	//resultsHT["HashTableLinear"] += timeMeasureHashTableLinear([](HashTableLinear& hashTab, int key, int j) { hashTab.insert(key, j); }, i, 1);
	//	//resultsHT["HashTableDouble"] += timeMeasureHashTableDouble([](HashTableDouble& hashTab, int key, int j) { hashTab.insert(key, j); }, i, 1);
	//	//resultsHT["HashTableQuadric"] += timeMeasureHashTableQuadric([](HashTableQuadric& hashTab, int key, int j) { hashTab.insert(key, j); }, i, 1);
	//	//resultsHT["HashTableRobinHood"] += timeMeasureHashTableRobinHood([](HashTableRobinHood& hashTab, int key, int j) { hashTab.insert(key, j); }, i, 1);
	//}

	//cout << "-----------------------------------" << endl;
	//for (const auto& result : resultsHT) {
	//	cout << result.first << ": " << result.second / 50 << endl;
	//}
	//cout << "-----------------------------------" << endl;

	vector<int> nums = { 50, 1000, 10000};

	for (int k = 0; k < 3; k++) {
		map<string, long long> resultsHT;

		for (int i = 0; i < nums[k]; i++) {
			resultsHT["HashTableChaining"] += timeMeasureHashTableChaining([](HashTableChaining& hashTab, int key, int j) { hashTab.insert(key, j); }, i, 1);
			resultsHT["HashTableLinear"] += timeMeasureHashTableLinear([](HashTableLinear& hashTab, int key, int j) { hashTab.insert(key, j); }, i, 1);
			resultsHT["HashTableQuadric"] += timeMeasureHashTableQuadric([](HashTableQuadric& hashTab, int key, int j) { hashTab.insert(key, j); }, i, 1);
			resultsHT["HashTableDouble"] += timeMeasureHashTableDouble([](HashTableDouble& hashTab, int key, int j) { hashTab.insert(key, j); }, i, 1);
			resultsHT["HashTableRobinHood"] += timeMeasureHashTableRobinHood([](HashTableRobinHood& hashTab, int key, int j) { hashTab.insert(key, j); }, i, 1);
		}

		cout << "-----------------------------------" << endl;
		for (const auto& result : resultsHT) {
			cout << result.first << ": " << result.second / nums[k] << endl;
		}
		cout << "-----------------------------------" << endl;
	}

	return 0;
}
