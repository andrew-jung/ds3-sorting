#include "ShellSort.h"
#include <iostream>
using namespace std;

ShellSort::ShellSort() {}
ShellSort::~ShellSort() {}

int* ShellSort::sort(int* unsortedArray, int arraySize) {
	int i, j, increment;

	for (increment = arraySize / 2; increment > 0; increment /= 2) {
		for (i = increment; i < arraySize; i++) {
			int temp = unsortedArray[i];

			for (j = i; j >= increment; j -= increment) {
				if (temp < unsortedArray[j - increment]){
					unsortedArray[j] = unsortedArray[j - increment];
				}
				else{
					break;
				}
			}
			unsortedArray[j] = temp;
		}
	}
	return unsortedArray;
}