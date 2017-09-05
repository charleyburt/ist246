#include "SimpleSLL.h"
#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main() {

  using namespace std;

  SimpleSLL list;

  for (int i = 0; i < 10; i++) {
    list.add(i);
  }

  cout << "Initial list has " << list.size() << " nodes:" << endl;
  list.print();
  
  
  return EXIT_SUCCESS;
}