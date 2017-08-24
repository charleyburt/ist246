#include "AVLTree.h"
#include <cstdlib>
#include <iostream>
#include <string>

int main() {
  using namespace std;

  AVLTree<int> avl;

  // randomize the same way each time
  srand(68333);

  cout << "Initial avl has " << avl.size() << " nodes" << endl;
  cout << "Tree: " << avl << endl;
  avl.printAsTree();

  cout << "\nInserting 45." << endl;
  avl.insert(45);
  cout << "Now avl has " << avl.size() << " nodes" << endl;
  cout << "Tree: " << avl << endl;
  avl.printAsTree();

  cout << "\nInserting ";
  for (int i = 0; i < 10; i++) {
    int d = rand() % 200;
    cout << d << " ";
    avl.insert(d);
  }
  cout << "\nNow avl has " << avl.size() << " nodes" << endl;
  cout << "Tree: " << avl << endl;
  avl.printAsTree();

  cout << "\nInserting duplicate 175." << endl;
  avl.insert(175);
  cout << "\nNow avl has " << avl.size() << " nodes" << endl;
  cout << "Tree: " << avl << endl;
  avl.printAsTree();

  cout << "\nCopy constructor." << endl;
  AVLTree<int> avl1(avl);
  cout << "\nNew avl has " << avl1.size() << " nodes" << endl;
  cout << "Tree: " << avl1 << endl;
  avl.printAsTree();

  cout << "\nSearching." << endl;
  cout << "avl " << (avl.contains(159) ? "does" : "does not") << " contain 159"
       << endl;
  cout << "avl " << (avl.contains(160) ? "does" : "does not") << " contain 160"
       << endl;

  cout << "\nRemoving 160 and 45." << endl;
  avl.remove(160);
  avl.remove(45);
  cout << "avl " << (avl.contains(45) ? "does" : "does not") << " contain 45"
       << endl;
  cout << "avl " << (avl.contains(160) ? "does" : "does not") << " contain 160"
       << endl;
  cout << avl << endl;
  avl.printAsTree();

  cout << "\nClearing tree." << endl;
  avl.clear();
  cout << "\nNow avl has " << avl.size() << " nodes" << endl;
  cout << "Tree: " << avl << endl;
  cout << "avl " << (avl.contains(159) ? "does" : "does not") << " contain 159"
       << endl;
  cout << "avl " << (avl.contains(160) ? "does" : "does not") << " contain 160"
       << endl;
  cout << "\nNew avl has " << avl1.size() << " nodes" << endl;
  cout << "Tree: " << avl1 << endl;
  avl1.printAsTree();

  cout << "\nAssignment operator." << endl;
  avl = avl1;
  cout << "\nNow avl has " << avl1.size() << " nodes" << endl;
  cout << "Tree: " << avl1 << endl;
  avl1.printAsTree();

  cout << "\nAllocating dynamic BST and filling:" << endl;
  AVLTree<int> *pAvl = new AVLTree<int>();
  for (int i = 0; i < 20; i++) {
    pAvl->insert(rand() % 200);
  }
  cout << "New avl has " << pAvl->size() << " nodes" << endl;
  cout << "Tree: " << *pAvl << endl;
  pAvl->printAsTree();

  cout << "Clearing and trying to make a chain" << endl;
  pAvl->clear();
  for (int i = 0; i < 20; i++) {
    pAvl->insert(i);
  }
  cout << *pAvl << endl;
  pAvl->printAsTree();

  cout << "Freeing dynamic tree." << endl;
  delete pAvl;

  return EXIT_SUCCESS;
}
