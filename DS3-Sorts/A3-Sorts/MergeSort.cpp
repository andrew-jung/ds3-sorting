#include "MergeSort.h"
#include <iostream>
using namespace std;

MergeSort::MergeSort() {}
MergeSort::~MergeSort() {}

int* MergeSort::sort(int* unsortedArray, int arraySize) {
	int sortSize = arraySize / 2; // Partition in half

	// Recursive sorting: 
	if (arraySize > 1) {
		return merge(sort(unsortedArray, sortSize), sortSize, sort(&unsortedArray[sortSize], arraySize - (sortSize)), arraySize - (sortSize));
	}
	else {
		return unsortedArray;
	}
}

// Merge post:
int* MergeSort::merge(int* leftArray, int leftSize, int* rightArray, int rightSize) {
	int tempArraySize = leftSize + rightSize;
	int* tempArray = new int[tempArraySize];
	int leftIndex = 0;
	int rightIndex = 0;

	for (int i = 0; i < tempArraySize; i++) {
		if (leftIndex >= leftSize){
			tempArray[i] = rightArray[rightIndex++];
		}
		else if (rightIndex >= rightSize) { 
			tempArray[i] = leftArray[leftIndex++];
		}
		else if (leftArray[leftIndex] <= rightArray[rightIndex]){
			tempArray[i] = leftArray[leftIndex++];
		}
		else { 
			tempArray[i] = rightArray[rightIndex++];
		}
	}
	return tempArray; // Sorted.
}

