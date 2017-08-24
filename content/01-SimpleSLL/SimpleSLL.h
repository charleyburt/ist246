#pragma once

#include <stdexcept>

//-----------------------------------------------------------
// class definitions
//-----------------------------------------------------------

/**
 * Class representing a simple singly-linked list of integers.
 */
class SimpleSLL {
private:
  //-------------------------------------------------------
  // inner class definition
  //-------------------------------------------------------

  /**
   * Class representing nodes in the singly-linked list.
   */
  class Node {
  public:
    /**
     * Default constructor. Make a new Node with data and next
     * pointer set to zero.
     */
    Node() : data(0), pNext(0) {}

    /**
     * Initializing constructor. Make a new Node with the specified
     * data and next pointer values.
     *
     * \param d Integer data value for the node.
     * \param pN Pointer to the next Node in the list, or 0 if
     * this is the last Node.
     */
    Node(int d, Node *pN) : data(d), pNext(pN) {}

    int data;
    /**< Integer payload of the Node. */

    Node *pNext;
    /**< Pointer to the next Node in the list, or 0 if
      this is the last node. */
  };

public:
  /**
   * Default constructor. Make an empty list.
   */
  SimpleSLL() : pHead(0), n(0u) {}

  /**
   * Destructor. Delete the contents of this list.
   */
  ~SimpleSLL();

  /**
   * Add a value to the front of the list.
   *
   * \param i Value to add to the list.
   */
  void add(int i);

  /**
   * Remove all the elements of the list.
   */
  void clear();

  /**
   * Determine if a specific value is in the list.
   *
   * \param i Integer value to search for.
   *
   * \return Index of first occurrence of i in the list, or
   * -1 if it is not in the list.
   */
  int contains(int i) const;

  /**
   * Get the value at a specified location.
   *
   * \param idx Index of the value to get.
   *
   * \return Value at location idx in the list
   */
  int get(unsigned idx) const;

  /**
   * Determine if the list is empty.
   *
   * \return true if the list is empty, false otherwise
   */
  bool isEmpty() const { return size() == 0u; }

  /**
   * Remove the value at a specified location.
   *
   * \param idx Index of the element to remove.
   *
   * \return Value that was in location idx.
   */
  int remove(unsigned idx);

  /**
   * Print the contents of this list to the standard output.
   */
  void print() const;

  /**
   * Change the value at a specified index to another value.
   *
   * \param idx Index of the value to change.
   *
   * \param i New value to place in position idx.
   */
  void set(unsigned idx, int i);

  /**
   * Get the number of integers in the list.
   *
   * \return The number of integers in the list.
   */
  unsigned size() const { return n; }

private:
  Node *pHead; /**< Pointer to the first Node in the list, or 0 if
                         the list is empty. */

  unsigned n; /**< Number of integers in the list. */
};
