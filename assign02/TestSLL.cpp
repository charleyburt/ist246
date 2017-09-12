#include "SortedSLL.h"
#include <cstdlib>
#include <iostream>
#include <string>

int main() {

  using namespace std;

  SLL<int> list;


    list.add(5);
    cout << list << endl;
    list.add(4);
    cout << list << endl;
    list.add(8);
    cout << list << endl;
    list.add(0);
    cout << list << endl;
    list.add(7);
    cout << list << endl;
    list.add(6);
    cout << list << endl;
    list.add(3);
    cout << list << endl;
    list.add(1);
    cout << list << endl;
    list.add(2);
    cout << list << endl;
    list.add(9);
    cout << list << endl;


  return EXIT_SUCCESS;
}
