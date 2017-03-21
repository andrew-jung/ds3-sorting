#include "MainArray.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "ISort.h"

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <chrono> //time measurement

using namespace std;
using namespace std::chrono;

// TODO:
// Fix time to ms (current is current computer time)	: Done
// Fix sorts : only output to file for sorts 1000, do NOT time 1000 one : Done
// Other sorts (size > 1000), no output file, just time		: Done
// Could probably recursively do functions since the only thing changing is array size:

//Initial Array Size and Unsorted Array
const int arraySize = 100000;
static int unsortedArray[arraySize];

// Generates the copy, needed for every sort
int* generateCopy() {
	int* copiedArray = new int[arraySize];

	// Copy array
	for (int i = 0; i < arraySize; i++)
		copiedArray[i] = unsortedArray[i];

	return copiedArray;
}

//Opens the Read file.
ifstream openFileRead(string textName) {
	ifstream fin;
	fin.open(textName);

	//Verifying if file encountered a failure and if file is open
	if (fin.fail() || !fin.is_open())
		cout << "Input file opening failed.";

	return fin;
}

//Opens the Write file.
ofstream openFileWrite(string outText) {
	ofstream fout;
	fout.open(outText);

	//Verifying if file encountered a failure and if file is open
	if (fout.fail() || !fout.is_open())
		cout << "Output file opening failed.";

	return fout;
}

//Opens the Read/Write file.
fstream openFileReadWrite(string outText) {
	fstream fio;
	fio.open(outText);

	//Verifying if file encountered a failure and if file is open
	if (fio.fail() || !fio.is_open())
		cout << "File opening failed.";

	return fio;
}

//Displays the Timer to the Console.
void displayStartEndTime(high_resolution_clock::time_point startTime, high_resolution_clock::time_point endTime, string sortType) {
	cout << sortType << endl;
	double diff = duration_cast<milliseconds>(endTime - startTime).count();
	cout << "Time Elapsed: " << diff << "ms" << endl << endl;
}

//Performs the passed in sort functions.
void performSort(ISort* sorter, string sortType, int size, ofstream& fout = ofstream()) {
	int* arrayCopy = generateCopy(); // Creates the unsorted array COPY.
	high_resolution_clock::time_point startTime = high_resolution_clock::now(); // Start time.
	int* sortedArray = sorter->sort(arrayCopy, size); // Sort from paramter.
	high_resolution_clock::time_point endTime = high_resolution_clock::now(); // End time.

	if (size > 1000) { 
		displayStartEndTime(startTime, endTime, sortType); // Displays to console, does not write to file.
	}
	else if (size == 1000) {
		//Writes to the file.
		fout << sortType << endl;
		fout << "------------" << endl;
		for (int i = 0; i < size; i++)
			fout << sortedArray[i] << endl;
		fout.close();
	}
}

int main() {
	//Creates the unsorted array.
	MainArray myArray;
	myArray.fillArray(unsortedArray, arraySize);

	cout << "Starting Sorts:" << endl << endl;

	performSort(new BubbleSort(), "Bubble Sort 1,000: ", 1000, openFileWrite("bubbleSort.txt")); // Write file
	performSort(new BubbleSort(), "Bubble Sort 25,000: ", 25000); // do not write file
	performSort(new BubbleSort(), "Bubble Sort 50,000: ", 50000); // do not write file
	performSort(new BubbleSort(), "Bubble Sort 75,000: ", 75000); // do not write file
	performSort(new BubbleSort(), "Bubble Sort 100,000: ", 100000); // do not write file

	performSort(new SelectionSort(), "Selection Sort 1,000: ", 1000, openFileWrite("selectionSort.txt"));
	performSort(new SelectionSort(), "Selection Sort 25,000: ", 25000);
	performSort(new SelectionSort(), "Selection Sort 50,000: ", 50000);
	performSort(new SelectionSort(), "Selection Sort 75,000: ", 75000);
	performSort(new SelectionSort(), "Selection Sort 100,000: ", 100000);

	performSort(new InsertionSort(), "Insertion Sort 1,000: ", 1000, openFileWrite("insertionSort.txt"));
	performSort(new InsertionSort(), "Insertion Sort 25,000: ", 25000);
	performSort(new InsertionSort(), "Insertion Sort 50,000: ", 50000);
	performSort(new InsertionSort(), "Insertion Sort 75,000: ", 75000);
	performSort(new InsertionSort(), "Insertion Sort 100,000: ", 100000);

	performSort(new ShellSort(), "Shell Sort 1,000: ", 1000, openFileWrite("shellSort.txt"));
	performSort(new ShellSort(), "Shell Sort 25,000: ", 25000);
	performSort(new ShellSort(), "Shell Sort 50,000: ", 50000);
	performSort(new ShellSort(), "Shell Sort 75,000: ", 75000);
	performSort(new ShellSort(), "Shell Sort 100,000: ", 100000);

	performSort(new MergeSort(), "Merge Sort 1,000: ", 1000, openFileWrite("mergeSort.txt"));
	performSort(new MergeSort(), "Merge Sort 25,000: ", 25000);
	performSort(new MergeSort(), "Merge Sort 50,000: ", 50000);
	performSort(new MergeSort(), "Merge Sort 75,000: ", 75000);
	performSort(new MergeSort(), "Merge Sort 100,000: ", 100000);

	performSort(new QuickSort(), "Quick Sort 1,000: ", 1000, openFileWrite("quickSort.txt"));
	performSort(new QuickSort(), "Quick Sort 25,000: ", 25000);
	performSort(new QuickSort(), "Quick Sort 50,000: ", 50000);
	performSort(new QuickSort(), "Quick Sort 75,000: ", 75000);
	performSort(new QuickSort(), "Quick Sort 100,000: ", 100000);

	_getch();
}