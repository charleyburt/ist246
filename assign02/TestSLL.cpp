#include "SortedSLL.h"
#include <cstdlib>
#include <iostream>
#include <string>

/**
 * Test Program to make sure the modified add() method works as expected
 *
 * \authors <Charley Burtwistle, Logan>
 * \date <September 13, 2017>
 */

int main() {

  using namespace std;

  SLL<int> list;
  
  //create an array of unsorted ints
  int testArray [10] = {5,4,8,0,7,6,3,1,2,9};
  
  
  //show the user the ints are unsorted
  cout << "Here are the unsorted numbers: \n";
  for (int unsortedNumbers : testArray){
    cout << unsortedNumbers << " ";

  }
  
  cout << endl;
  
  
  //add them all to the list, which will be sorted
  cout << "\nHere we add each of the unsorted numbers to a list, which will be sorted (hopefully): \n";
  for (int unsortedNumbers : testArray){
    cout << "add " << unsortedNumbers << ": ";
    list.add(unsortedNumbers);
    cout << list << endl;
  }



  return EXIT_SUCCESS;
}
