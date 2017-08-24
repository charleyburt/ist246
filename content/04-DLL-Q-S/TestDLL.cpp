#include <cstdlib>
#include <iostream>
#include <string>
#include "DLL.h"

int main() {

  using namespace std;

  DLL<int> list;

  cout << "DLL::<<" << endl;

  for (int i = 0; i < 10; i++) {
    list.addFirst(i);
  }

  for (int i = 5; i >= 1; i--) {
    list.addLast(i);
  }

  cout << "DLL iterator" << endl;
  for (DLL<int>::Iterator i = list.begin(); i != list.end(); ++i) {
    cout << *i << " ";
  }
  cout << endl;

  cout << list << endl;

  cout << "List " << (list.isEmpty() ? "is" : "is not") << " empty" << endl;
  cout << "List has " << list.size() << " elements" << endl;

  cout << "First element: " << list.getFirst() << endl;
  cout << "Last element: " << list.getLast() << endl;

  cout << "Removing first element: " << list.removeFirst() << endl;
  cout << list << endl;

  cout << "Removing last element: " << list.removeLast() << endl;
  cout << list << endl;

  cout << "List " << (list.isEmpty() ? "is" : "is not") << " empty" << endl;
  cout << "List has " << list.size() << " elements" << endl;

  cout << "Accessing odd indices: " << endl;
  for (unsigned i = 1; i < list.size(); i += 2) {
    cout << list.get(i) << " ";
  }

  cout << endl;

  cout << "Changing even indices: " << endl;
  for (unsigned i = 0; i < list.size(); i += 2) {
    list.set(i, -9);
  }

  cout << list << endl;

  cout << "Index of 5: " << list.contains(5) << endl;
  cout << "Index of 18: " << list.contains(18) << endl;

  cout << "Copying list:" << endl;
  DLL<int> list2(list);

  cout << list2 << endl;

  cout << "Assigning list:" << endl;
  DLL<int> list3;
  list3 = list;

  cout << list3 << endl;

  cout << "Removing at index 3: " << list.remove(3) << endl;
  cout << list << endl;

  cout << "Changing first element:" << endl;

  list.setFirst(65);
  cout << list << endl;

  cout << "Changing last element:" << endl;

  list.setLast(66);
  cout << list << endl;

  list.clear();

  cout << "List " << (list.isEmpty() ? "is" : "is not") << " empty" << endl;
  cout << "List has " << list.size() << " elements" << endl;

  return EXIT_SUCCESS;
}
