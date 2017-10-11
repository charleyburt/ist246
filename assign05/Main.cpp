#include <cstdlib>
#include <iostream>
#include <stdexcept>


/**
 * 

 * \authors <Charley Burtwistle, Brian Spencer>
 * \date <September 27, 2017>
 */


//-----------------------------------------------------------
// Body of code (what is executed when called from the command line)
//-----------------------------------------------------------


void iterativeSearch(int n) {
    using namespace std;
  
    int testArray [10] = {1,2,3,4,5,6,7,8,9,10};
    
    int high = 9;
    int low = 0;
    int mid = high/2;
    int instances = 0;
    
    while(n != testArray[mid] and high >= low){
        instances ++;
        if(n<testArray[mid]){
            high = mid;
            mid = (high-low)/2;
        }else{
            low = mid;
            mid = (high-low)/2;
        }
    }
    cout << instances << endl;
    cout << mid << endl;
    

    
    
  }



int main() {
  using namespace std;

  
  
  iterativeSearch(2);
  return EXIT_SUCCESS;
  

  
}


  
  
 

  


