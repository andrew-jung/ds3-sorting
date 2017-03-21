#include "ISort.h"
using namespace std;

class MergeSort : public ISort {
private:
	int* merge(int* leftArray, int leftSize, int* rightArray, int rightSize);
public:
	MergeSort();
	virtual ~MergeSort();

	virtual int* sort(int* unsortedArray, int arraySize);
};