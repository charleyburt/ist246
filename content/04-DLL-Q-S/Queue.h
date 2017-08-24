#pragma once

#include <iostream>
#include <stdexcept>
#include "DLL.h"

//-----------------------------------------------------------
// class definitions
//-----------------------------------------------------------

/**
 * Class representing a simple, templated queue, using a doubly-linked
 * list as the underyling data structure.
 */
template <class T> class Queue {
public:
  /**
   * Default constructor. Make a new, empty queue.
   */
  Queue() {}

  /**
   * Copy constructor. Make this queue just like an existing one.
   *
   * \param queue Queue to copy from.
   */
  Queue(const Queue<T> &queue);

  /**
   * Remove all the elements from this queue.
   */
  void clear() { list.clear(); }

  /**
   * Remove the first element from the queue.
   *
   * \return First element from the queue.
   */
  T dequeue();

  /**
   * Add an element to the end of the queue.
   *
   * \param a Element to add to the queue.
   */
  void enqueue(const T &a) { list.addLast(a); }

  /**
   * Determine if this queue is empty.
   *
   * \return True if the queue is empty, false otherwise.
   */
  bool isEmpty() const { return list.isEmpty(); }

  /**
   * Get the number of elements in the queue.
   *
   * \return Number of elements in the queue.
   */
  unsigned size() const { return list.size(); }

  /**
   * Overloaded assignment operator.
   *
   * \param queuen Queue to copy from.
   *
   * \return A reference to this queue, for chaining.
   */
  Queue<T> &operator=(const Queue<T> &queue);

  /**
   * Override of the stream insertion operator for Queue objects.
   *
   * \param out ostream object to output to, e.g., cout
   *
   * \param queue Queue to output
   *
   * \return the out ostream object
   */
  friend std::ostream &operator<<(std::ostream &out, const Queue<T> &queue) {

    out << queue.list;
    return out;
  }

private:
  /**
   * Doubly-linked list used as the underlying data structure for the
   * queue.
   */
  DLL<T> list;

  /**
   * Helper method to make this queue just like another one.
   *
   * \param queue Queue to copy from
   */
  void copy(const Queue<T> &queue);
};

//-----------------------------------------------------------
// function implementations
//-----------------------------------------------------------

/*
 * Implementation of the copy constructor.
 */
template <class T> Queue<T>::Queue(const Queue<T> &queue) { copy(queue); }

/*
 * Implementation of the copy helper method.
 */
template <class T> void Queue<T>::copy(const Queue<T> &queue) {
  clear();
  list = queue.list;
}

/*
 * Implementation of the dequeue method.
 */
template <class T> T Queue<T>::dequeue() {
  if (list.isEmpty()) {
    throw std::out_of_range("Empty queue in Queue::dequeue()");
  }
  return list.removeFirst();
}

/*
 * Overloaded assignment operator implementation.
 */
template <class T> Queue<T> &Queue<T>::operator=(const Queue<T> &queue) {
  copy(queue);
  return *this;
}
