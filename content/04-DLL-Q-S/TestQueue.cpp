#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "Queue.h"

int main() {
  using namespace std;

  Queue<int> q1;

  for (int i = 0; i < 10; i++) {
    q1.enqueue(i);
  }

  cout << q1 << " " << q1.size() << endl;

  Queue<int> q2(q1);

  cout << q2 << " " << q2.size() << endl;

  cout << "q2 " << (q2.isEmpty() ? "is" : "is not") << " empty" << endl;

  q1.clear();

  cout << "q1 " << (q1.isEmpty() ? "is" : "is not") << " empty" << endl;

  cout << q1 << endl;

  Queue<int> q3;

  q3 = q2;

  try {
    while (true) {
      cout << q2.dequeue() << endl;
    }
  } catch (std::out_of_range oor) {
    cout << oor.what() << endl;
  }

  cout << q3 << endl;

  return EXIT_SUCCESS;
}
