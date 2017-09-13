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



    // list.add(5);
    // cout << list << endl;
    // list.add(4);
    // cout << list << endl;
    // list.add(8);
    // cout << list << endl;
    // list.add(0);
    // cout << list << endl;
    // list.add(7);
    // cout << list << endl;
    // list.add(6);
    // cout << list << endl;
    // list.add(3);
    // cout << list << endl;
    // list.add(1);
    // cout << list << endl;
    // list.add(2);
    // cout << list << endl;
    // list.add(9);
    // cout << list << endl;



  return EXIT_SUCCESS;
}
