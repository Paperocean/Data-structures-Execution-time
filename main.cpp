#include <iostream>
#include <chrono>
#include <vector>
#include "measureFunctions.h"
using namespace std;

int main()
{
	int count = 0;
	int highest = 0;

	for (int i = 0; i < 100; i++) {
		long long malArrayTime = pushTimeMeasureMallocArray(i);
		long long arrayTime = pushTimeMeasureArray(i);
		if (malArrayTime < arrayTime) {
			highest = i;
			cout << "I = " << highest << endl;
			cout << "Time taken by ArrayMalloc: " << malArrayTime << " ns" << endl;
			cout << "Time taken by Array: " << arrayTime << " ns" << endl;
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
