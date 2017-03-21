#include "QuickSort.h"
#include <iostream>
using namespace std;

QuickSort::QuickSort() {}
QuickSort::~QuickSort() {}


int* QuickSort::sort(int* unsortedArray, int arraySize) {
	if (arraySize > 1) {
		int pivotIndex = partition(unsortedArray, arraySize);
		sort(unsortedArray, pivotIndex); //sorts data less than pivot
		sort(&unsortedArray[pivotIndex + 1], arraySize - pivotIndex - 1); //sorts data greater than pivot
	}
	return unsortedArray;
}

int QuickSort::partition(int* unsortedArray, int arraySize) {
	int pivotIndex = 0;
	int pivotValue = unsortedArray[arraySize - 1];

	for (int i = 0; i < arraySize - 1; i++) {
		if (unsortedArray[i] <= pivotValue) {
			int temp = unsortedArray[i];
			unsortedArray[i] = unsortedArray[pivotIndex];
			unsortedArray[pivotIndex] = temp;
			pivotIndex++;
		}
	}

	int temp = unsortedArray[pivotIndex];
	unsortedArray[pivotIndex] = unsortedArray[arraySize - 1];
	unsortedArray[arraySize - 1] = temp;

	return pivotIndex;
}