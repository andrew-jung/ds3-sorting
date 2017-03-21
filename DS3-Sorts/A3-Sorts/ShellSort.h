#include "ISort.h"
using namespace std;

class ShellSort : public ISort {
public:
	ShellSort();
	virtual ~ShellSort();
	virtual int* sort(int* unsortedArray, int arraySize);
};