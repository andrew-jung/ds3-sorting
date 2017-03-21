#include "ISort.h"
using namespace std;

class InsertionSort : public ISort {
public:
	InsertionSort();
	virtual ~InsertionSort();

	virtual int* sort(int* unsortedArray, int arraySize);
};