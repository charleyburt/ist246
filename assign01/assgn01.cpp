#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

/**
 * Program to analyze the frequency of each number in PowerBall lottery
 * drawings.
 *
 * \authors <your names here>
 * \date <date code was authored>
 */
int main() {
	using namespace std;
	
	// open input file
	ifstream inFile;
	inFile.open("numbers.txt");
	
	// read numbers, one line at a time
	int b1, b2, b3, b4, b5, b6;
	while( inFile >> b1 ) {
		inFile >> b2;
		inFile >> b3;
		inFile >> b4;
		inFile >> b5;
		inFile >> b6;

		// TODO: replace this output code with your code to count
		// the frequency of each number
		cout << b1 << "\t"
		     << b2 << "\t"
		     << b3 << "\t"
		     << b4 << "\t"
		     << b5 << "\t"
		     << b6 << endl;
	}

	inFile.close();

	// TODO: output the frequency for each number, as described in the
	// assignment

	return EXIT_SUCCESS;
}
