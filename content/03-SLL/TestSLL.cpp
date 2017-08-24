#include <cstdlib>
#include <iostream>
#include <string>
#include "SLL.h"

int main() {

  using namespace std;

  SLL<int> list;

  for (int i = 0; i < 10; i++) {
    list.add(i);
  }

  cout << "Initial list has " << list.size() << " nodes:" << endl;
  cout << list << endl;

  cout << "\nIterating!" << endl;
  for (SLL<int>::Iterator i = list.begin(); i != list.end(); ++i) {
    *i += 3;
    cout << *i << endl;
  }

  SLL<string> list2;

  list2.add("country");
  list2.add("their");
  list2.add("of");
  list2.add("aid");
  list2.add("the");
  list2.add("to");
  list2.add("come");
  list2.add("to");
  list2.add("men");
  list2.add("good");
  list2.add("all");
  list2.add("for");
  list2.add("time");
  list2.add("the");
  list2.add("is");
  list2.add("Now");

  cout << "Printing string list with iterators:" << endl;
  for (SLL<string>::Iterator i = list2.begin(); i != list2.end(); ++i) {
    cout << *i << " ";
  }
  cout << endl;

  try {
    cout << "\nTesting too many increments:" << endl;
    for (SLL<int>::Iterator i = list.begin(); true; ++i) {
      ; // do nothing
    }
  } catch (std::out_of_range oor) {
    cout << oor.what() << endl;
  }

  try {
    cout << "\nTesting dereference past list end:" << endl;
    SLL<string>::Iterator i = list2.begin();
    while (i != list2.end()) {
      ++i;
    }
    // dereference iterator
    cout << *i << endl;
  } catch (std::out_of_range oor) {
    cout << oor.what() << endl;
  }

  return EXIT_SUCCESS;
}
