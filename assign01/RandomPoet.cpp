#include "SimpleSLL.h"
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <fstream>

int main() {

  using namespace std;

  SimpleSLL list;
  
  cout <<"Welcome to the random poetry generator!" <<
         "Please wait while the dictiionary is loaded." << endl;
  
  //open input file
  ifstream inFile;
  inFile.open("dictionary.txt");
  
  string all ;
  while( inFile >> all){
    list.add(all);
  }
  
  
  int again = 1;
  int lines;
  cout << "Let's make some poetry, dude! Enter the number of lines:";
  cin >> lines;
  while (cin.fail()) {
    cout << "Please Enter an int." << std::endl;
    cin.clear();
    cin.ignore(256,'\n');
    cin >> lines;
}
    

  
  int words;
  cout << "Radical! Now, enter the number of words per line: ";
  cin >> words;
  while (cin.fail()) {
  cout << "Please Enter an int." << std::endl;
  cin.clear();
  cin.ignore(256,'\n');
  cin >> lines;
    }
  

  

  cout << "Would you like to make another poem? Enter 1 for yes, 0 for no: ";
  cin >> again;
 




  


  cout << "Getting a Random string " << list.getRandom() << endl;
  cout << "Getting a Random string " << list.getRandom() << endl;
  cout << "Initial list has " << list.size() << " nodes:" << endl;
  inFile.close();
  
  return EXIT_SUCCESS;
}