#include "ISort.h"
using namespace std;

class QuickSort : public ISort {
private:
	int partition(int* unsortedArray, int arraySize);
public:
	QuickSort();
	virtual ~QuickSort();

	virtual int* sort(int* unsortedArray, int arraySize);
};