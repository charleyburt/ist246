#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "SimpleSLL.h"

int main() {

  using namespace std;

  SimpleSLL list;

  for (int i = 0; i < 10; i++) {
    list.add(i);
  }

  cout << "Initial list has " << list.size() << " nodes:" << endl;
  list.print();
  cout << "List " << (list.isEmpty() ? "is" : "is not") << " empty." << endl;

  cout << "\nResult of searching for 0: " << list.contains(0) << endl;
  cout << "\nResult of searching for 9: " << list.contains(9) << endl;
  cout << "\nResult of searching for 4: " << list.contains(4) << endl;
  cout << "\nResult of searching for 13: " << list.contains(13) << endl;

  try {
    cout << "\nGetting 1st element: " << list.get(0u) << endl;
    cout << "\nGetting 5th element: " << list.get(4u) << endl;
    cout << "\nGetting 10th element: " << list.get(9u) << endl;
    cout << "\nGetting 11th element: " << list.get(10u) << endl;
  } catch (const std::out_of_range &oor) {
    cout << "Caught std::out_of_range: " << oor.what() << endl;
  }

  try {
    cout << "\nRemoving first element: " << list.remove(0u) << endl;
    list.print();
    cout << "\nRemoving fourth element: " << list.remove(3u) << endl;
    list.print();
    cout << "\nRemoving last element: " << list.remove(list.size() - 1u)
         << endl;
    list.print();
    cout << "\nRemoving past last element: " << list.remove(list.size())
         << endl;
  } catch (const std::out_of_range &oor) {
    cout << "Caught std::out_of_range: " << oor.what() << endl;
  }

  try {
    cout << "\nSetting first element to 13:" << endl;
    list.set(0, 13);
    list.print();
    cout << "\nSetting third element to 14:" << endl;
    list.set(2, 14);
    list.print();
    cout << "\nSetting last element to 15:" << endl;
    list.set(list.size() - 1, 15);
    list.print();
    cout << "\nSetting past last element to 16:" << endl;
    list.set(list.size(), 16);
    list.print();
  } catch (const std::out_of_range &oor) {
    cout << "Caught std::out_of_range: " << oor.what() << endl;
  }

  list.clear();
  cout << "\nClearing list; now it has " << list.size() << " nodes:" << endl;
  list.print();
  cout << "List " << (list.isEmpty() ? "is" : "is not") << " empty." << endl;

  cout << "\nResult of searching for 4: " << list.contains(4) << endl;

  return EXIT_SUCCESS;
}
