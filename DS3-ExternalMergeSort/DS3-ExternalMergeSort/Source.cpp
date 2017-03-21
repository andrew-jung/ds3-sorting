#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

void createArray(string filePath, int arraySize);
bool mergeFiles(fstream& input1, fstream& input2, fstream* output1, fstream* output2, int runSize);
void mergeSort(string sourceFileName);

int main() {
	int arraySize = 20000; // Array size
	createArray("array.txt", arraySize); 
	mergeSort("array.txt");
	return 0;
}

void createArray(string filePath, int arraySize) { // Creates a random array of arraySize and puts it in the filePath.
	srand(time(NULL)); // Random seed

	fstream file(filePath, ios::out);
	for (int i = 0; i < arraySize; i++){ // Fill array.
		file << rand() << ' ';
	}
}

// Merges the "runs" present in the first two files and outputs the results in the other 2 files
bool mergeFiles(fstream& input1, fstream& input2, fstream* output1, fstream* output2, int runSize) {
	int counter1 = 0, counter2 = 0, mergeCount = 0;	/*	counter 1 = number of integers read from "input1"
													counter 2 = number of integers read from "input2
													mergeCount = Total Number of merges performed */
	int temp1 = 0, temp2 = 0;						/*	Temp1 = Contains values read from input1
													Temp2 = Contains values read from input2 */
	fstream* activeOutput = output1;
	fstream* inactiveOutput = output2;

	while (true){							
		if (!(input1 >> temp1)) // Break when no more values (input1)
			break;
		else if (!(input2 >> temp2)) { // If input2 has run out of values, dump the temp1 variable to prevent data loss and then break
			*activeOutput << temp1 << ' ';
			break;
		}

		counter1 = 1;
		counter2 = 1;

		while (true) { // Merge loop, break when out of values (maybe bad practice to have infinite loop?)
			if (temp1 < temp2) {		// If temp1 is smaller, place in the output file
				*activeOutput << temp1 << ' ';
				counter1++; 

				if (counter1 > runSize || !(input1 >> temp1)) { // Check if all integers read and file is out of values
					*activeOutput << temp2 << ' '; // If it has run out of values, temp2 is dumped and loop breaks
					counter2++;
					break;
				}
			}
			else { // otherwise if temp2 is smaller, it is placed in the output File
				*activeOutput << temp2 << ' ';
				counter2++;
				if (counter2 > runSize || !(input2 >> temp2)) { // Check if all integers read and file is out of values
					*activeOutput << temp1 << ' ';				/* If it has run out of values, temp2 is dumped and loop breaks*/
					counter1++;
					break;
				}
			}
		}

		while (counter1 <= runSize && input1 >> temp1) { // Dumps the remaining values from either of the "runs" onto output 
			*activeOutput << temp1 << ' ';
			counter1++;
		}

		while (counter2 <= runSize && input2 >> temp2)
		{
			*activeOutput << temp2 << ' ';
			counter2++;
		}

		swap(activeOutput, inactiveOutput); // Swaps the output files
		mergeCount++;
	}

	while (input1 >> temp1) {	 // Dumps any integers left in either of the files
		*activeOutput << temp1 << ' ';
	}

	while (input2 >> temp2) {
		*activeOutput << temp2 << ' ';
	}

	if (mergeCount == 0){ 	// Returns "true" if mergeSort is complete.
		return true;
	}
	else { 
		return false;
	}
}

void mergeSort(string sourceFileName) {
	fstream file;
	int temp1, temp2, i = 0;

	// File variables and paths
	string subListFile1 = "file1.txt", subListFile2 = "file2.txt", incrMergeFile1 = "file3.txt", incrMergeFile2 = "file4.txt";
	fstream File1, File2, File3, File4;

	file.open(sourceFileName, ios::in);
	File1.open(subListFile1, ios::out);
	File2.open(subListFile2, ios::out);

	// Integers are from array.txt/source, then divided into two groups (File1, File2) which will be 'run'.
	while (file >> temp1) {
		if (file >> temp2) { // If 2nd int read successfully, place both integers in the file, else place just one

			if (temp1 > temp2) { // Sort two numbers
				swap(temp1, temp2);
			}

			if (i % 2 == 0) { // Place numbers into files alternating
				File1 << temp1 << ' ' << temp2 << ' ';
			}

			else {
				File2 << temp1 << ' ' << temp2 << ' ';
			}
		}

		else {
			if (i % 2 == 0) {
				File1 << temp1 << ' ';
			}

			else {
				File2 << temp1 << ' ';
			}
		}
		i++;
	}
	file.close();
	File1.close();
	File2.close(); // File 1,2 now have unsorted

	int runSize = 2; //Merging starts with an initial "run" size of 2 (since two groups)

	File1.open(subListFile1, ios::in);
	File2.open(subListFile2, ios::in);
	File3.open(incrMergeFile1, ios::out);
	File4.open(incrMergeFile2, ios::out);

	/* The first 2 files contain Runs of sorted data. Where each file contains half of the runs.
	The 3rd and 4th file will contain the output from the function i.e. the merged runs from
	the input files. These runs will be twice the size of previous runs */

	// This loop merges the files until mergeSort is complete 
	while (!mergeFiles(File1, File2, &File3, &File4, runSize)) {
		// The output files of the previous merge will now be used for input of next merge, files are swapped.
		swap(subListFile1, incrMergeFile1);
		swap(subListFile2, incrMergeFile2);

		// The files are closed an opened again in order to make the swap effective, could improve this
		File1.close();		
		File1.open(subListFile1, ios::in);

		File2.close();		
		File2.open(subListFile2, ios::in);

		File3.close();		
		File3.open(incrMergeFile1, ios::out);

		File4.close();		
		File4.open(incrMergeFile2, ios::out);


		runSize *= 2; // The "mergeFile" function has increased the size of "runs" by combining them 
	}

	File1.close();
	File2.close();
	File3.close();
	File4.close();

	// File1 contains the final results of the mergeSort, results are copied back to the source file
	file.open(sourceFileName, ios::out);
	File1.open(subListFile1, ios::in);
	while (File1 >> temp1) {
		file << temp1 << ' ';
	}

	file.close();
	File1.close();
}