#pragma once

#include <functional>
#include <iostream>
#include <stdexcept>
#include "../assign03/SLL.h"

//-----------------------------------------------------------
// class definitions
//-----------------------------------------------------------

/**
 * Templated hash table class.
 */
template <class T> class HashTable {

public:
  /**
   * Create a new hash table.
   */
  HashTable(unsigned size);

  /**
   * Create a new hash table just like an existing one.
   *
   * \param Existing hash table to copy from.
   */
  HashTable(const HashTable<T> &table);

  /**
   * Destructor. Free the memory used by the hash table.
   */
  ~HashTable();

  /**
   * Insert an element into the hash table.
   *
   * \param val Element to insert.
   * \return true if val was inserted into the table, false if
   * val was already in the list.
   */
  bool add(const T &val);

  /**
   * Remove all of the elements from the hash table.
   */
  void clear();
  
  /**
   * Does the table contain this value?
   * 
   * \param val Element to search for
   * \return true if val is in the hash table, false otherwise
   */
  bool contains(const T &val);

  /**
   * Determine if this hash table is empty.
   *
   * \return True if the heap is empty, false otherwise.
   */
  bool isEmpty() const { return false; /* TODO: finish */ }

  /**
   * Override of the stream insertion operator for HashTable objects.
   *
   * \param out ostream object to output to, e.g., cout
   *
   * \param table HashTable to output
   *
   * \return the out ostream object
   */
  friend std::ostream &operator<<(std::ostream &out, const HashTable<T> &table) {
    for(unsigned i = 0U; i < table.numBuckets; i++) {
      out << *table.ppBuckets[i] << std::endl;
    }

    return out;
  }

  /**
   * Override of the assignment operator for HashTable objects.
   *
   * \param table HashTable to copy from
   * \return Reference to this HashTable, for chaining purposes.
   */
  HashTable<T> &operator=(const HashTable<T> &table);
  
  /**
   * Remove an element from the hash table.
   * 
   * \param val Element to remove from the table.
   * \return True if the element was removed, false if it was not in the table
   * to begin with.
   */
  bool remove(const T &val);

  /**
   * Get the number of elements in the hash table.
   *
   * \return Number of elements in the heap.
   */
  unsigned size() const {
    return n; 
  }

private:
  /**
   * Copy the contents of one hash table into this one.
   *
   * \param table hash table to copy from.
   */
  void copy(const HashTable<T> &table);
  
  /**
   * Free all the memory used by this hash table.
   */
  void destroy();
  
  /**
   * Simple hash function based on C++ hash implementation.
   * 
   * \param key Element being hashed
   * \return Hash value based on C++ hash implementation. 
   */
  unsigned hash(const T& key) { return  ((unsigned) std::hash<T>{}(key)) % numBuckets; }
  
  /**
   * Array of pointers to singly-linked lists holidng the buckets.
   */
  SLL<T> **ppBuckets;
  
  /**
   * Number of buckets in the hash table.
   */
  unsigned numBuckets;
  
  /**
   * Number of elements in the hash table.
   */
  unsigned n;

};

//-----------------------------------------------------------
// function implementations
//-----------------------------------------------------------

/*
 * Implementation of the HashTable constructor.
 */
template <class T> HashTable<T>::HashTable(unsigned size = 16u) : numBuckets(size), n(0U) {
  // allocate array of pointers to SLLs
  ppBuckets = new SLL<T>*[numBuckets];
  
  // create the SLLs
  for(unsigned i = 0U; i < numBuckets; i++) {
    ppBuckets[i] = new SLL<T>();
  }
}

/*
 * Copy constructor implementation.
 */
template <class T> HashTable<T>::HashTable(const HashTable<T> &table) { copy(table); }

/*
 * Destructor implementation.
 */
template <class T> HashTable<T>::~HashTable() {
  destroy();
}

/*
 * Implementation of add() function.
 */
template <class T> bool HashTable<T>::add(const T &val) {
  unsigned i = hash(val);                 // find bucket for val
  if(ppBuckets[i]->contains(val) < 0) {   // does the bucket contain val?
    ppBuckets[i]->add(val);               // if not, add it,
    n++;                                  // increase size and 
    return true;                          // return true
  } else {
    return false;                         // otherwise, return false
  }
}

/*
 * Implementation of the clear() function.
 */
template <class T> void HashTable<T>::clear() {
  // remove all elements from the SLLs
  for(unsigned i = 0U; i < numBuckets; i++) {
    ppBuckets[i]->clear();
  }
  
  // change size
  n = 0U;
}

/* 
 * Implementation of the contains() function
 */
template <class T> bool HashTable<T>::contains(const T& val) {
  return ppBuckets[hash(val)]->contains(val) != -1;
}

/*
 * Implementation of the copy() function.
 */
template <class T> void HashTable<T>::copy(const HashTable<T> &table) {

  // copy information from parameter
  numBuckets = table.numBuckets;
  n = table.n;
  
  // allocate memory and copy existing values
  ppBuckets = new SLL<T>*[numBuckets];
  for(unsigned i = 0U; i < numBuckets; i++) {
    ppBuckets[i] = new SLL<T>(*table.ppBuckets[i]);
  }
}

/*
 * Implementation of destry method.
 */
template <class T> void HashTable<T>::destroy() {
  // delete all the SLLs
  for(unsigned i = 0U; i < numBuckets; i++) {
    delete ppBuckets[i];
  }
  
  // delete the array of pointers
  delete [] ppBuckets;
}

/*
 * Implementation of assignment operator.
 */
template <class T> HashTable<T> &HashTable<T>::operator=(const HashTable<T> &table) {
  destroy();      // get rid of existing dynamic memory
  copy(table);    // copy from existing table
  return *this;   // return reference to this table for assignment chaining
}

/*
 * Implementation of remove function.
 */
template <class T> bool HashTable<T>::remove(const T &val) {
  unsigned i = hash(val);                   // get the bucket
  int idx = ppBuckets[i]->contains(val);    // is val in the bucket?
  if(idx >= 0) {                            // if so, ...
    ppBuckets[i]->remove(idx);              // ... remove it,
    n--;                                    // decrease size, and
    return true;                            // return true
  } else {
    return false;                           // otherwise, return false
  }
}