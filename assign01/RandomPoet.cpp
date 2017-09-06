#include "SimpleSLL.h"
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <fstream>

int main() {

  using namespace std;

  SimpleSLL list;
  
  //open input file
  ifstream inFile;
  inFile.open("dictionary.txt");
  
  string all ;
  while( inFile >> all){
    list.add(all);
  }
  



  


  cout << "Getting a Random string " << list.getRandom() << endl;
  cout << "Getting a Random string " << list.getRandom() << endl;
  cout << "Initial list has " << list.size() << " nodes:" << endl;
  inFile.close();
  
  return EXIT_SUCCESS;
}