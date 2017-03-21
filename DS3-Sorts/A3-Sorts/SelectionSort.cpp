#include "SelectionSort.h"
#include <iostream>
using namespace std;

SelectionSort::SelectionSort() {}
SelectionSort::~SelectionSort() {}

// Abstract implementation:
int* SelectionSort::sort(int* unsortedArray, int arraySize) {
	int outer, inner, min;

	for (outer = 0; outer < arraySize - 1; outer++) {
		min = outer;

		for (inner = outer + 1; inner < arraySize; inner++) {
			if (unsortedArray[inner] < unsortedArray[min])
				min = inner; // Min number
		}
		// Swap
		int temp = unsortedArray[outer];
		unsortedArray[outer] = unsortedArray[min];
		unsortedArray[min] = temp;
	}
	return unsortedArray;
}