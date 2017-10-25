#include <algorithm>    // for STL sort
#include <chrono>       // for seeding PRNG
#include <iostream>     // for input and output
#include <random>       // for Mersenne Twister PRNG
#include <cstdio>       // for printf

/**
 * 
 * Method to perform a iterative binary search.
 * n is the number to search for
 * length is the length of the array
 * arr[] is the array of numbers
 */ 
double iterBinSearch(long n, long length, long arr[]) {
    
    // initialize high, low, mid and number of comparisons   
    long high = length - 1;
    long low = 0;
    long mid = high/2;
    double numOfComparisons = 0.0;
    
    // while the number hasn't been found and high/low have not crossed
    while(n != arr[mid] && high >= low) {
        // add three to number of comparisons
        numOfComparisons+=1;
        if(n < arr[mid]) { // if n happens to be less than the value of current mid
            high = mid - 1;
            mid = (high - low)/2 + low;
            numOfComparisons+=1;
        } else if(n > arr[mid]) { // if n happens to be more than value of current mid
            low = mid + 1;
            mid = (high - low)/2 + low;
            numOfComparisons+=2;
        }
    } 
    
    numOfComparisons++;
    
    return numOfComparisons;
    
}

/**
 * 
 * 
 * 
 * 
 */
double recurBinSearch(long n, long low, long high, long arr[]) {
    
    // initialize mid as high and low are given as parameters
    long mid = (high - low)/2 + low;
    
    if(high < low || arr[mid] == n) { // check if high is less than low or value was found
        return 1;
    } else if(n > arr[mid]) { // is the value we are searching for greater than mid
        return 2 + recurBinSearch(n, low, mid - 1, arr);
    } else { // is the value we are searching for less than mid
        return 3 + recurBinSearch(n, mid + 1, high, arr);
    }
}

/**
 * 
 * 
 * 
 * 
 */
int main() {
    
    using namespace std;
    
    // create Mersenne Twister PRNG
    mt19937 prng(chrono::system_clock::now().time_since_epoch().count());
    
    printf("%9s \t %s \t %s \t %s \n", "n", "iter", "recur", "lg(n)");
    
    
    // loop to create and search an array of size 2^i
    for(int i = 6; i <= 27; i++) {
        
        // power has to be one less than i for using << to do exponents with 2
        int power = i - 1;
        int length = 2 << power;
        long *arr = new long[length];
        
        // fill the array with numbers
        for(int j = 0; j < length; j++) {
            arr[j] = prng();
        }
        
        // sort using STL sort algorithm
        sort(arr, arr + length);   // parameters: pointer to first and one-past last
        
        // total values for recursive and iterative methods
        double iterTotal = 0;
        double recTotal = 0;
        
        for(int j = 0; j < 1000; j++) {
            long search = prng();
            iterTotal += (iterBinSearch(search, length, arr));
            recTotal += (recurBinSearch(search, 0, length - 1, arr));
        }
        
        // the average iter value, average recursive value and lg(n) to be printed
        double iterAvg = iterTotal/1000;
        double recAvg = recTotal/1000;
        int lg = log2(length);
        
        // prints output to command line
        printf("%*d", 9, length);
        printf("\t %4.2f", iterAvg);
        printf("\t %4.2f", recAvg);
        printf("\t %*d", 4, lg);
        printf("\n");
        
        delete [] arr;
        
    }
    
    return EXIT_SUCCESS;
    
}
  
  
 

  


