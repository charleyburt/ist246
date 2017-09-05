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


    list.add("HelloWorld");
  

  cout << "Initial list has " << list.size() << " nodes:" << endl;
  list.print();
  inFile.close();
  
  return EXIT_SUCCESS;
}