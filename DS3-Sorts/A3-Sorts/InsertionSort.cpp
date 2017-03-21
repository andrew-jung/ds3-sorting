#include "InsertionSort.h"
#include <iostream>
using namespace std;

InsertionSort::InsertionSort() {}
InsertionSort::~InsertionSort() {}

int* InsertionSort::sort(int* unsortedArray, int arraySize) {
	int outer, inner, temp;

	for (outer = 1; outer < arraySize; outer++) {
		inner = outer;

		while (inner > 0 && unsortedArray[inner - 1] > unsortedArray[inner]) {
			temp = unsortedArray[inner];
			unsortedArray[inner] = unsortedArray[inner - 1];
			unsortedArray[inner - 1] = temp;
			inner--;
		}
	}
	return unsortedArray;
}