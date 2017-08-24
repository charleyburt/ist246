#include "SLL.h"
#include <cstdlib>
#include <iostream>
#include <string>

int main() {

  using namespace std;

  SLL<int> list;

  for (int i = 0; i < 10; i++) {
    list.add(i);
  }

  cout << "Initial list has " << list.size() << " nodes:" << endl;
  cout << list << endl;
  cout << "List " << (list.isEmpty() ? "is" : "is not") << " emtpy." << endl;

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
    cout << list << endl;
    cout << "\nRemoving fourth element: " << list.remove(3u) << endl;
    cout << list << endl;
    cout << "\nRemoving last element: " << list.remove(list.size() - 1u)
         << endl;
    cout << list << endl;
    cout << "\nRemoving past last element: " << list.remove(list.size())
         << endl;
  } catch (const std::out_of_range &oor) {
    cout << "Caught std::out_of_range: " << oor.what() << endl;
  }

  try {
    cout << "\nSetting first element to 13:" << endl;
    list.set(0, 13);
    cout << list << endl;
    cout << "\nSetting third element to 14:" << endl;
    list.set(2, 14);
    cout << list << endl;
    cout << "\nSetting last element to 15:" << endl;
    list.set(list.size() - 1, 15);
    cout << list << endl;
    cout << "\nSetting past last element to 16:" << endl;
    list.set(list.size(), 16);
    cout << list << endl;
  } catch (const std::out_of_range &oor) {
    cout << "Caught std::out_of_range: " << oor.what() << endl;
  }

  list.clear();
  cout << "\nClearing list; now it has " << list.size() << " nodes:" << endl;
  cout << "List " << (list.isEmpty() ? "is" : "is not") << " emtpy." << endl;
  cout << list << endl;

  cout << "\nResult of searching for 4: " << list.contains(4) << endl;

  SLL<string> sList;

  sList.add("Now");
  sList.add("is");
  sList.add("the");
  sList.add("time");
  sList.add("for");
  sList.add("all");
  sList.add("good");
  sList.add("men");
  sList.add("to");
  sList.add("come");
  sList.add("to");
  sList.add("the");
  sList.add("aid");
  sList.add("of");
  sList.add("their");
  sList.add("country");

  cout << "\nString list: " << endl;
  cout << sList << endl;

  cout << "Position of country: " << sList.contains("country") << endl;
  cout << "Position of Now: " << sList.contains("Now") << endl;
  cout << "Position of aid: " << sList.contains("aid") << endl;

  SLL<string> sList2(sList);

  cout << "Copied string list:" << endl;
  cout << sList2 << endl;

  SLL<string> sList3;

  sList3 = sList2;

  cout << "Assigned string list: " << endl;
  cout << sList3 << endl;

  sList3.remove(3);
  sList3.remove(4);

  sList2 = sList3;

  cout << "Next assigned list: " << endl;
  cout << sList3 << endl;
  cout << sList2 << endl;

  return EXIT_SUCCESS;
}
