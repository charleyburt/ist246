#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <list>
#include <random>
#include <vector>
#include "HashTable.h"
#include <fstream>
#include "SimpleBST.h"

/**
 * Spell Checker
 * 
 * Reads in a dictionary (stores it in a HashTable)
 * 
 * Reads in War and Peace
 * 
 * Outputs the misspelled words in WAP
 *
 * \authors <Charley Burtwistle, Lange>
 * \date <November 29, 2017>
 */



/**
 * Application entry point.
 */
int main() {
    using namespace std;
    
    //create a new HashTable
    HashTable<string> *stringTable = new HashTable<string>(200000U);
    
    //open input file
    ifstream inFile;
    inFile.open("dictionary.txt");
    
    //add all the words to the HashTable
    string all;
    while(inFile >> all){
        stringTable->add(all);
    }
    
    //create a new Binary Search Tree
    SimpleBST<string>bst;
    
    //open input file
    ifstream inFile2;
    inFile2.open("wap.txt");
    
    // go through all the words
    string all2;
    while(inFile2 >> all2){
        
        //if its spelled right
        if (stringTable->contains(all2)){
            //do nothing
        }
        //if its spelled wrong
        else{
            //add it to the bst
            bst.insert(all2);
        }
    }
    
    //print out the misspelled words
    // edited the override of the stream insertion operator
        //so it wouldnt print the brackets
    // edited the preorderprint
        //so it would print a new line character after each word
   cout << bst << endl;


    
    return EXIT_SUCCESS;
}