#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

/**
 * Program to analyze the frequency of each number in PowerBall lottery
 * drawings.
 *
 * \authors <Charley Burtwistle, Chase Stone>
 * \date <August 28, 2017>
 */
 
int main() {
	using namespace std;
	
	// open input file
	ifstream inFile;
	inFile.open("numbers.txt");
	
	// Create an array and set every value to 0
	int* array = new int[60];
	for (int i = 0; i<60; i++){
	array[i]=0;
	}
	
	// for each possible number (1-59)
	for (int i = 1; i<=59; i++){

	
		// read numbers, one line at a time
		int b1, b2, b3, b4, b5, b6;
		while( inFile >> b1 ) {
			inFile >> b2;
			inFile >> b3;
			inFile >> b4;
			inFile >> b5;
			inFile >> b6;
			
			
			//every time a number appears,
			//add one to it's value in the array
			array[b1] ++;
			array[b2] ++;
			array[b3] ++;
			array[b4] ++;
			array[b5] ++;
			array[b6] ++;


			}//end while
			
			
		//output index,value
		cout << i << ":" << "\t" << array[i] << "\n" << endl;

	}//end for
	
	// clean up
	delete array;
	inFile.close();

	return EXIT_SUCCESS;
}// end main
