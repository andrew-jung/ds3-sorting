#include "ISort.h"
using namespace std;

class BubbleSort : public ISort {
public:
	BubbleSort();
	virtual ~BubbleSort();

	virtual int* sort(int* unsortedArray, int arraySize);
};