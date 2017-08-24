#pragma once

#include <algorithm> // for max function
#include <iostream>
#include <sstream> // for int to string conversion
#include <string>

//-----------------------------------------------------------
// class definitions
//-----------------------------------------------------------

/**
 * Templated binary search tree, using the AVL balancing technique
 * to guarantee that the insert, remove, and search functions remain
 * O(lg n) in the worst case.
 *
 * Sources:
 * http://www.geeksforgeeks.org/avl-tree-set-1-insertion/
 * http://www.geeksforgeeks.org/avl-tree-set-2-deletion/
 */
template <class T> class AVLTree {
private:
  //-------------------------------------------------------
  // inner class definition
  //-------------------------------------------------------

  /**
   * Private nested class representing a node in the AVL tree.
   */
  class Node {
  public:
    /**
     * Constructor. Make a new leaf node in the tree, with
     * the specified data value.
     *
     * \param val Type T payload to store in the node.
     */
    Node(const T &val) : data(val), ht(1), pLeft(0), pRight(0) {}

    /**
     * Print tree from here as a horizontally-oriented ASCII
     * tree diagram.
     *
     * \param prefix String prefix of the line thus far.
     * \param isTail True if this node ends the line, false
     * otherwise.
     */
    void print(std::string prefix, bool isTail);

    /** Type T payload of the node. */
    T data;

    /** Height of the node. */
    int ht;

    /** Pointer to the left child of this node. */
    Node *pLeft;

    /** Pointer to the right child of this node. */
    Node *pRight;
  };

public:
  /**
   * Default constructor. Create an empty AVL tree.
   */
  AVLTree() : pRoot(0), n(0u) {}

  /**
   * Copy constructor. Make a new AVL tree just like an
   * existing one.
   *
   * \param tree AVL tree to copy.
   */
  AVLTree(const AVLTree<T> &tree) { pRoot = copy(tree.pRoot); }

  /**
   * Destructor. Free all the memory used by the AVL tree.
   */
  ~AVLTree() { clear(); }

  /**
   * Remove all the elements from the AVL tree.
   */
  void clear();

  /**
   * Determine if the AVL tree contains a given value.
   *
   * \param val Value to search for.
   * \return True if the AVL tree contains val, false
   * otherwise.
   */
  bool contains(const T &val) const { return contains(val, pRoot); }

  /**
   * Insert an element into the AVL tree.
   *
   * \param val Element to insert into the AVL tree.
   */
  void insert(const T &val) { pRoot = insert(val, pRoot); }

  /**
   * Determine if the binary search tree is empty.
   *
   * \return True if the tree is empty, false otherwise.
   */
  bool isEmpty() { return n == 0u; }

  /**
   * Override of the stream insertion operator for AVLTree objects.
   * Prints via a preorder traversal.
   *
   * \param out ostream object to output to, e.g., cout
   *
   * \param tree AVLTree to output
   *
   * \return the out ostream object
   */
  friend std::ostream &operator<<(std::ostream &out, const AVLTree<T> &tree) {
    out << "[";
    tree.preOrderPrint(out, tree.pRoot);
    out << "]";
    return out;
  }

  /**
   * Override of the assignment operator.
   *
   * \param tree AVLTree to copy from.
   * \return A reference to the newly created AVL tree,
   * for chaining.
   */
  AVLTree &operator=(const AVLTree<T> &tree);

  /**
   * Print the AVL tree as a horizontally-oriented ASCII tree
   * diagram.
   */
  void printAsTree() const;

  /**
   * Remove an item from the AVL tree. If the item isn't
   * in the tree, take no action.
   *
   * \param val Item to be removed from the tree.
   */
  void remove(const T &val) { pRoot = remove(val, pRoot); }

  /**
   * Get the number of nodes in the binary search tree.
   *
   * \return Number of nodes in the tree.
   */
  unsigned size() { return n; }

private:
  /** Pointer to the root node of the AVL tree. */
  Node *pRoot;

  /** Number of elements in the AVL tree. */
  unsigned n;

  /**
   * Recursive helper for clear function.
   *
   * \param pCurr Pointer to current location in the deletion
   * process.
   */
  void clear(Node *pCurr);

  /**
   * Recursive helper for contains function.
   *
   * \param val Value to search for.
   * \param pCurr Pointer to the current node in the search.
   * \return True if the tree contains val, false otherwise.
   */
  bool contains(const T &val, Node *pCurr) const;

  /**
   * Recursive helper function for copying trees.
   *
   * \param pCurr Pointer to the current node in the tree being
   * copied.
   * \param pPar Pointer to the newly created node's parent.
   * \return Pointer to the newly created node, or 0 if no node
   * was created.
   */
  Node *copy(Node *pCurr);

  /**
   * Get the balance factor for a node in the tree.
   *
   * \param pCurr Node to examine.
   * \return Balance factor for the node, i.e., the difference of the
   * height of the left subtree and the height of the right subtree.
   */
  int getBalance(const Node *pCurr) const;

  /**
   * Determine the height of a node in the tree.
   *
   * \param pCurr Pointer to the node in question.
   * \return height of the node.
   */
  int height(const Node *pCurr) const;

  /**
   * Recursive helper function for inserting.
   *
   * \param val Value to add to the tree
   * \param pCurr Pointer to the current node in the insertion
   * process.
   * \return Pointer to the root of the balance subtree where the node
   * was inserted (or where it already exists)
   */
  Node *insert(const T &val, Node *pCurr);

  /**
   * Left-rotate the subtree rooted and pX.
   *
   * \param pX Pointer to the root node of the subtree to be
   * rotated.
   * \return Pointer to the new root of the rotated subtree.
   */
  Node *leftRotate(Node *pX);

  /**
   * Find the node containing the smallest value in a subtree.
   *
   * \param pCurr Pointer to the root of the subtree to search.
   * \return Pointer to the node containing the smallest value in
   * the subtree rooted as pCurr.
   */
  Node *minValueNode(Node *pCurr);

  /**
   * Recursive helper function for operator>>.
   *
   * \param out ostream object to output to, e.g., cout
   * \param pCurr Pointer to current node in the traversal.
   */
  void preOrderPrint(std::ostream &out, Node *pCurr) const;

  /**
   * Recursive helper for remove function.
   *
   * \param val Item to remove from the tree.
   * \param pCurr Pointer to the current node in the traversal of the
   * tree.
   * \param Pointer to the root of the balanced subtree where the node
   * was removed (or where it would have been)
   */
  Node *remove(const T &val, Node *&pCurr);

  /**
   * Right-rotate the subtree rooted and pY.
   *
   * \param pY Pointer to the root node of the subtree to be
   * rotated.
   * \return Pointer to the new root of the rotated subtree.
   */
  Node *rightRotate(Node *pY);
};

//-----------------------------------------------------------
// function implementations
//-----------------------------------------------------------

/*
 * Public clear function implementation.
 */
template <class T> void AVLTree<T>::clear() {
  clear(pRoot);
  n = 0u;
  pRoot = 0;
}

/*
 * Implementation for recursive clear helper function.
 */
template <class T> void AVLTree<T>::clear(Node *pCurr) {
  if (pCurr != 0) {
    clear(pCurr->pLeft);
    clear(pCurr->pRight);
    delete pCurr;
  }
}

/*
 * Implementation for recursive contains helper function.
 */
template <class T> bool AVLTree<T>::contains(const T &val, Node *pCurr) const {
  // empty? Doesn't contain val for sure
  if (pCurr == 0) {
    return false;
  }
  // found it?
  else if (pCurr->data == val) {
    return true;
  }
  // go left?
  else if (val < pCurr->data) {
    return contains(val, pCurr->pLeft);
  }
  // go right!
  else {
    return contains(val, pCurr->pRight);
  }
}

/*
 * Implementation for recursive copy helper function.
 */
template <class T> typename AVLTree<T>::Node *AVLTree<T>::copy(Node *pCurr) {

  if (pCurr != 0) {
    Node *pN = 0;
    pN = new Node(pCurr->data);
    n++;
    pN->pLeft = copy(pCurr->pLeft);
    pN->pRight = copy(pCurr->pRight);

    return pN;
  } else {
    return 0;
  }
}

/*
 * Implementation for getBalance function.
 */
template <class T> int AVLTree<T>::getBalance(const Node *pCurr) const {
  if (pCurr == 0) {
    return 0;
  } else {
    return height(pCurr->pLeft) - height(pCurr->pRight);
  }
}

/*
 * Implementation for height function.
 */
template <class T> int AVLTree<T>::height(const Node *pCurr) const {
  if (pCurr == 0) {
    return 0;
  } else {
    return pCurr->ht;
  }
}

/*
 * Implementation for recursive insert helper function.
 */
template <class T>
typename AVLTree<T>::Node *AVLTree<T>::insert(const T &val, Node *pCurr) {

  // Normal recursive binary search tree insertion
  if (pCurr == 0) {
    n++;
    return new Node(val);
  } else if (val < pCurr->data) {
    pCurr->pLeft = insert(val, pCurr->pLeft);
  } else if (val > pCurr->data) {
    pCurr->pRight = insert(val, pCurr->pRight);
  }

  // update height
  pCurr->ht = std::max(height(pCurr->pLeft), height(pCurr->pRight)) + 1;

  // get balance factor
  int balance = getBalance(pCurr);

  // if unbalanced, which case?

  // left left
  if (balance > 1 && val < pCurr->pLeft->data) {
    return rightRotate(pCurr);
  }

  // right right
  if (balance < -1 && val > pCurr->pRight->data) {
    return leftRotate(pCurr);
  }

  // left right
  if (balance > 1 && val > pCurr->pLeft->data) {
    pCurr->pLeft = leftRotate(pCurr->pLeft);
    return rightRotate(pCurr);
  }

  // right left
  if (balance < -1 && val < pCurr->pRight->data) {
    pCurr->pRight = rightRotate(pCurr->pRight);
    return leftRotate(pCurr);
  }

  // if no imbalance, just return
  return pCurr;
}

/*
 * Implementation for left rotate function.
 */
template <class T> typename AVLTree<T>::Node *AVLTree<T>::leftRotate(Node *pX) {
  // get pX's child and grandchild
  Node *pY = pX->pRight;
  Node *pT2 = pY->pLeft;

  // perform rotation
  pY->pLeft = pX;
  pX->pRight = pT2;

  // update heights
  pX->ht = std::max(height(pX->pLeft), height(pX->pRight)) + 1;
  pY->ht = std::max(height(pY->pLeft), height(pY->pRight)) + 1;

  // return new root
  return pY;
}

/*
 * Implementation of minValueNode function.
 */
template <class T>
typename AVLTree<T>::Node *AVLTree<T>::minValueNode(Node *pCurr) {
  while (pCurr->pLeft != 0) {
    pCurr = pCurr->pLeft;
  }

  return pCurr;
}

/*
 * Implementation for overridden assignment operator.
 */
template <class T> AVLTree<T> &AVLTree<T>::operator=(const AVLTree<T> &tree) {
  // clean existing tree
  clear();

  // copy tree
  pRoot = copy(tree.pRoot);

  return *this;
}

/*
 * Implementation for recursive printing helper function.
 */
template <class T>
void AVLTree<T>::preOrderPrint(std::ostream &out, Node *pCurr) const {

  if (pCurr != 0) {
    out << pCurr->data << " ";

    preOrderPrint(out, pCurr->pLeft);
    preOrderPrint(out, pCurr->pRight);
  }
}

/*
 * Implementation of Node print() function.
 * Algorithm due to:
 * stackoverflow.com/questions/4965335/how-to-print-binary-tree-diagram
 */
template <class T>
void AVLTree<T>::Node::print(std::string prefix, bool isTail) {
  using namespace std;

  // C++ 11 method to convert Node's data to a string object
  string s;
  ostringstream convert;
  convert << data;
  s = convert.str();

  cout << prefix + (isTail ? "L__ " : "|-- ") + s << endl;

  if (pLeft != 0 && pRight != 0) {
    pLeft->print(prefix + (isTail ? "    " : "|   "), false);
    pRight->print(prefix + (isTail ? "    " : "|   "), true);
  } else if (pLeft != 0 && pRight == 0) {
    pLeft->print(prefix + (isTail ? "    " : "|   "), true);
  } else if (pLeft == 0 && pRight != 0) {
    pRight->print(prefix + (isTail ? "    " : "|   "), false);
  }
}

/*
 * Implementation of printAsTree() function.
 */
template <class T> void AVLTree<T>::printAsTree() const {
  using namespace std;

  if (pRoot == 0) {
    cout << "<empty>" << endl;
  } else {
    string s = "";
    pRoot->print(s, true);
    cout << endl;
  }
}

/*
 * Implementation for recursive remove helper function.
 */
template <class T>
typename AVLTree<T>::Node *AVLTree<T>::remove(const T &val, Node *&pCurr) {

  // standard binary search tree delete
  if (pCurr == 0) {
    return pCurr;
  }

  // go left?
  if (val < pCurr->data) {
    pCurr->pLeft = remove(val, pCurr->pLeft);
  }
  // go right?
  else if (val > pCurr->data) {
    pCurr->pRight = remove(val, pCurr->pRight);
  }
  // found it!
  else {
    // one child or no child
    if ((pCurr->pLeft == 0) || (pCurr->pRight == 0)) {
      Node *pT = 0;
      if (pT == pCurr->pLeft) {
        pT = pCurr->pRight;
      } else {
        pT = pCurr->pLeft;
      }

      // No child case
      if (pT == 0) {
        pT = pCurr;
        pCurr = 0;
      }
      // One child case
      else {
        pCurr = pT;
      }
    }
    // node with two children: get inorder successor
    else {
      Node *pT = minValueNode(pCurr->pRight);
      // copy data to this node
      pCurr->data = pT->data;

      // delete successor
      pCurr->pRight = remove(pT->data, pCurr->pRight);
    }
  }

  // if there was only one node, stop here
  if (pCurr == 0) {
    return pCurr;
  }

  // update height of current node
  pCurr->ht = std::max(height(pCurr->pLeft), height(pCurr->pRight)) + 1;

  // get balace factor for this node
  int balance = getBalance(pCurr);

  // unbalanced? see which case we have
  // left left
  if (balance > 1 && getBalance(pCurr->pLeft) >= 0) {
    return rightRotate(pCurr);
  }

  // left right
  if (balance > 1 && getBalance(pCurr->pLeft) < 0) {
    pCurr->pLeft = leftRotate(pCurr->pLeft);
    return rightRotate(pCurr);
  }

  // right right
  if (balance < -1 && getBalance(pCurr->pRight) <= 0) {
    return leftRotate(pCurr);
  }

  // right left
  if (balance < -1 && getBalance(pCurr->pRight) > 0) {
    pCurr->pRight = rightRotate(pCurr->pRight);
    return leftRotate(pCurr);
  }

  return pCurr;
}

/*
 * Implementation for right rotation function.
 */
template <class T>
typename AVLTree<T>::Node *AVLTree<T>::rightRotate(Node *pY) {
  // get pY's child and grandchild
  Node *pX = pY->pLeft;
  Node *pT2 = pX->pRight;

  // perform rotation
  pX->pRight = pY;
  pY->pLeft = pT2;

  // update heights
  pY->ht = std::max(height(pY->pLeft), height(pY->pRight)) + 1;
  pX->ht = std::max(height(pX->pLeft), height(pX->pRight)) + 1;

  // return new root
  return pX;
}
