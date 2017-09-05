#include "SimpleSLL.h"
#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main() {

  using namespace std;

  SimpleSLL list;


    list.add("HelloWorld");
  

  cout << "Initial list has " << list.size() << " nodes:" << endl;
  list.print();
  
  
  return EXIT_SUCCESS;
}