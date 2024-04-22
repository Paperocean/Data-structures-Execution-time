#include <iostream>
#include <chrono>
#include <vector>
#include "measureFunctions.cpp"
using namespace std;

int main()
{
	int count = 0;
	int highest = 0;

	for (int i = 0; i < 100; i++) {
		auto malArrayTime = pushTimeMeasureMallocArray(i);
		auto arrayTime = pushTimeMeasureArray(i);
		if (malArrayTime < arrayTime) {
			highest = i;
			cout << "I = " << highest << endl;
			cout << "Time taken by ArrayMalloc: " << pushTimeMeasureMallocArray(i) << " ns" << endl;
			cout << "Time taken by Array: " << pushTimeMeasureArray(i) << " ns" << endl;
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
