#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "Stack.h"

int main() {
  using namespace std;

  Stack<int> stack;

  for (int i = 0; i < 10; i++) {
    stack.push(i);
  }

  cout << stack << " " << stack.size() << endl;

  Stack<int> st1(stack);
  Stack<int> st2;

  st2 = st1;

  cout << st1 << " " << st1.size() << endl;

  cout << st2 << " " << st1.size() << endl;

  stack.clear();

  cout << stack << " " << stack.size() << endl;

  cout << st1.peek() << endl;

  try {
    cout << stack.peek() << endl;
  } catch (std::out_of_range oor) {
    cout << oor.what() << endl;
  }

  try {
    while (true) {
      cout << st1.pop() << endl;
    }
  } catch (std::out_of_range oor) {
    cout << oor.what() << endl;
  }

  return EXIT_SUCCESS;
}
