#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <list>
#include <random>
#include <vector>

using namespace std;

/**
 * Determine if an array of unsigned integers is sorted in ascending order.
 * 
 * \param pArr Pointer to the first element of the array.
 * \param n Number of elements in the array.
 * \return true if the array is sorted in ascending order, false otherwise.
 */
bool isSorted(unsigned *pArr, unsigned n) {
    for(unsigned i = 0u; i < n - 1u; i++) {
        if(pArr[i] > pArr[i + 1u]) {
            return false;
        }
    }
    return true;
}

/**
 * Sort an array of unsigned integers using bucket sort.
 * 
 * \param pArr Pointer to the first element of the array.
 * \param n Number of elements in the array.
 */
void bucketSort(unsigned *pArr, unsigned n) {
    
    vector<unsigned>** ppBuckets = new vector<unsigned>*[256];
    
    for(unsigned i = 0u; i<256u; i++){
        ppBuckets[i] = new vector<unsigned>();
    }
    

    for(unsigned i = 0u; i < n; i++){
        unsigned index = pArr[i] >> 24;
        ppBuckets[index]->push_back(pArr[i]);
        
    }
    
    for(unsigned i = 0u; i < 256u; i++){
        sort(ppBuckets[i]->begin(),ppBuckets[i]->end());
    }
    
    unsigned idx = 0u;
    
    for(unsigned i = 0u; i <256; i++){
        
        for(unsigned j = 0u; j < ppBuckets[i]->size(); j++){
            
            pArr[idx] = ppBuckets[i]->at(j);
            idx += 1u;
        
        }
    }
    
    
    
    for(unsigned i = 0u; i<256u; i++){
        delete ppBuckets[i];
    }
    
    
}

/**
 * Application entry point.
 */
int main() {
    // Mersenne Twister PRNG
    mt19937 prng(chrono::system_clock::now().time_since_epoch().count());
    
    // size of arrays
    unsigned n = 10000000u;

    // create two arrays of size n
    unsigned *pArr1 = new unsigned[n];
    unsigned *pArr2 = new unsigned[n];

    // fill with identical pseudo-random values
    for(unsigned i = 0u; i < n; i++) {
        pArr1[i] = prng();
        pArr2[i] = pArr1[i];
    }
    
    sort(pArr1, pArr1 + n);     // sort 1st array with STL sort
    bucketSort(pArr2, n);       // sort 2nd array with bucketSort

    // output success or failure of each sort
    cout << "Array 1 " << (isSorted(pArr1, n) ? "is" : "is not") << " sorted." << endl;
    cout << "Array 2 " << (isSorted(pArr2, n) ? "is" : "is not") << " sorted." << endl;

    // free memory
    delete [] pArr1;
    delete [] pArr2;
    
    return EXIT_SUCCESS;
}
