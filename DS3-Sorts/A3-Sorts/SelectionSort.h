#include "ISort.h"
using namespace std;

class SelectionSort : public ISort {
public:
	SelectionSort();
	virtual ~SelectionSort();

	virtual int* sort(int* unsortedArray, int arraySize);
};