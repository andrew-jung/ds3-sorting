#include "BubbleSort.h"
#include <iostream>
using namespace std;

BubbleSort::BubbleSort() {}
BubbleSort::~BubbleSort() {}

int* BubbleSort::sort(int* unsortedArray, int arraySize) {
	int outer, inner;

	for (outer = arraySize - 1; outer > 0; outer--) {
		for (inner = 0; inner < outer; inner++) {
			if (unsortedArray[inner] > unsortedArray[inner + 1]) {
				int temp = unsortedArray[inner];
				unsortedArray[inner] = unsortedArray[inner + 1];
				unsortedArray[inner + 1] = temp;
			}
		}
	}
	return unsortedArray;
}