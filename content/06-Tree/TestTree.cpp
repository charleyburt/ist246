#include "Tree.h"
#include <cstdlib>
#include <iostream>

int main() {

  using namespace std;

  Tree<char> tree('m');

  Tree<char>::Handle loc = tree.rootHandle();

  cout << "Root value: " << *loc << ", with " << loc.numChildren()
       << " children." << endl;

  loc.addChild('a');
  loc.addChild('r');
  loc.addChild('k');

  cout << "added level 1, size is now: " << tree.size() << endl;
  cout << "root has " << loc.numChildren() << " children." << endl;
  cout << tree;
  cout << endl;

  loc = loc.getChild(0);
  loc.addChild('m');
  loc.addChild('e');

  cout << "added level 2, size is now: " << tree.size() << endl;
  cout << "loc has " << loc.numChildren() << " children." << endl;
  cout << tree;
  cout << endl;

  loc = loc.getChild(1);
  loc.addChild('y');
  loc.addChild('s');

  cout << "added level 3, size is now: " << tree.size() << endl;
  cout << "loc has " << loc.numChildren() << " children." << endl;
  cout << tree;
  cout << endl;

  loc = loc.getChild(0);
  loc.addChild('e');
  loc = loc.getParent();
  loc = loc.getChild(1);
  loc.addChild('n');

  cout << "added level 4, size is now: " << tree.size() << endl;
  cout << "loc has " << loc.numChildren() << " children." << endl;
  cout << tree;
  cout << endl;

  loc = loc.getChild(0);
  loc.addChild('b');
  loc.addChild('u');
  loc.addChild('r');
  loc.addChild('g');

  cout << "added level 5, size is now: " << tree.size() << endl;
  cout << "loc has " << loc.numChildren() << " children." << endl;
  cout << tree;
  cout << endl;

  Tree<char> tree2(tree);

  cout << "copied tree:" << endl;
  cout << tree2;
  cout << ", size is " << tree2.size() << endl;

  loc.prune();
  cout << "pruned level 5, size is now: " << tree.size() << endl;
  cout << "loc has " << loc.numChildren() << " children." << endl;
  cout << tree;
  cout << endl;

  tree2 = tree;
  cout << "assigned tree:" << endl;
  cout << tree2;
  cout << ", size is " << tree2.size() << endl;

  loc = loc.getParent();
  loc = loc.getParent();
  loc.prune();
  cout << "pruned levels 3 and 4, size is now: " << tree.size() << endl;
  cout << "loc has " << loc.numChildren() << " children." << endl;
  cout << tree;
  cout << endl;

  loc = tree.rootHandle();
  *loc = 'Z';
  cout << "changed root via handle dereferencing." << endl;
  cout << tree;
  cout << endl;

  return EXIT_SUCCESS;
}
