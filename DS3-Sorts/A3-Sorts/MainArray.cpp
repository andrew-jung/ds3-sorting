#include "MainArray.h"
#include <stdlib.h> 
#include <iostream>
using namespace std;

MainArray::MainArray() {}
MainArray::~MainArray() {}

// Fills the array with unsorted data.
void MainArray::fillArray (int* emptyArray, int arraySize) {
	for (int i = 0; i < arraySize; i++) {
		emptyArray[i] = rand() % rangeLimit;
	}
}
