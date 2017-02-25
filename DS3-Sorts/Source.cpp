#include <iostream>
#include <ctime>
#include "time.h"
#include <cstdlib>
using namespace std;
void bubbleSort(int arr[], int s);

void bubbleSort(int a[], int s);
void selectionSort(int a[], int s);
void insertionSort(int a[], int s);
void shellSort(int a[], int s);

// TODO: Quick sort, merge sort, write to file (size=1000), prompt for size vs hard code, all of Part 2

// TIMES:
// Sizes:       [1,000], [25,000], [50,000], [75,000], [100,000]
// Bubble:      [.002s], [1.542s], [6.39s], [14.432s], [26.012s]
// Selection:   [.001s], [.642s], [2.562s], [5.685s], [10.03s]
// Insertion:   [.001s], [.602s], [2.421s], [5.361s], [9.627s]
// Shell:       [0s], [.004s], [.012s], [.017s], [.026s]
// Merge:       [], [], [], [], []
// Quick:       [], [], [], [], []

int main() {
	bool loopAgain = true;
	while (loopAgain) {
		// Create random size array, filled with random elements: .
		srand((unsigned int)time(NULL));

		int size = 100000; // Enter array size here
		cout << "Size of array: " << size << endl;
		int *arr = new int[size]; // Allocate array size

		// Insert random integers in new array random sized
		for (int i = 0; i < size; i++) {
			arr[i] = rand() % 32768 + 1;
		}

		clock_t begin = clock(); // Timer start

		// bubbleSort(arr, size);

		// selectionSort(arr, size);

		// insertionSort(arr, size);

		shellSort(arr, size);

		clock_t end = clock(); // Timer end
		cout << "It took " << double(end - begin) / CLOCKS_PER_SEC << " seconds to sort this array for size of " << size << endl; // Timer
		delete[] arr; // Delete array memory

		cout << "Run again?: [y/n]" << endl;
		char a;
		cin >> a;
		loopAgain = a == 'y';
	}
	cout << "End" << endl;
	cin.get();
	return 0;
}

void bubbleSort(int a[], int s) {
	int outer, inner;
	for (outer = s - 1; outer > 0; outer--) {
		for (inner = 0; inner < outer; inner++) {
			if (a[inner] > a[inner + 1]) {
				int temp = a[inner];
				a[inner] = a[inner + 1];
				a[inner + 1] = temp;
			}
		}
	}
}

void selectionSort(int a[], int s) {
	int outer, inner, min;
	for (outer = 0; outer < s - 1; outer++) {
		min = outer;
		for (inner = outer + 1; inner < s; inner++) {
			if (a[inner] < a[min]) {
				min = inner;
			}
		}
		int temp = a[outer];
		a[outer] = a[min];
		a[min] = temp;
	}
}

void insertionSort(int a[], int s) {
	int i, j, tmp;
	for (i = 1; i < s; i++) {
		j = i;
		while (j > 0 && a[j - 1] > a[j]) {
			tmp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = tmp;
			j--;
		}
	}
}

void shellSort(int a[], int s) {
	int i, j, increment, temp;
	for (increment = s / 2; increment > 0; increment /= 2) {
		for (i = increment; i < s; i++) {
			temp = a[i];
			for (j = i; j >= increment; j -= increment) {
				if (temp < a[j - increment]) {
					a[j] = a[j - increment];
				}
				else {
					break;
				}
			}
			a[j] = temp;
		}
	}
}

// Merge sort
// Quicksort