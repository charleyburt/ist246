#include "SortedSLL.h"
#include <cstdlib>
#include <iostream>
#include <string>

int main() {

  using namespace std;

  SLL<int> list;
  
  int testArray [10] = {5,4,8,0,7,6,3,1,2,9};
  
  cout << "Here are the unsorted numbers: \n";
  for (int unsortedNumbers : testArray){
    cout << unsortedNumbers << " ";

  }
  
  cout << endl;
  
  cout << "\nHere we add each of the unsorted numbers to a list, which will be sorted (hopefully): \n";
  for (int unsortedNumbers : testArray){
    cout << "add " << unsortedNumbers << ": ";
    list.add(unsortedNumbers);
    cout << list << endl;
  }



  return EXIT_SUCCESS;
}
