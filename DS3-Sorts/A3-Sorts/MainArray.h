#include <iostream>
using namespace std;

class MainArray {
private:
	const int rangeLimit = 32767; // Range of random numbers (max 32 bit?)

public:
	MainArray();
	virtual ~MainArray();

	void fillArray(int* emptyArray, int arraySize); // Create, fill array with unsorted random numbers.
};