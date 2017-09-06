#include "SimpleSLL.h"
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <ctime>


int main() {
  

  using namespace std;

  SimpleSLL list;
  
  srand(time(0));
  
  cout <<"Welcome to the random poetry generator!" <<
         "Please wait while the dictiionary is loaded. \n" << endl;
  
  //open input file
  ifstream inFile;
  inFile.open("dictionary.txt");
  
  string all ;
  while( inFile >> all){
    list.add(all);
  }
  
  
  int again = 1;
  do{
    

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
  cin >> words;
    }
  
  cout << "\nHere's your poem man: \n" << endl;
  for (int i = 0; i<lines; i++){
    for (int j = 0; j<words; j++){
        cout << list.getRandom() << " ";
      
    }
    cout << "\n";
  }

  
  do{
  cout << "\nWould you like to make another poem? Enter 1 for yes, 0 for no: ";
  cin >> again;
    while (cin.fail()) {
    cout << "Please Enter an int." << std::endl;
    cin.clear();
    cin.ignore(256,'\n');
    cin >> again;
    } // make sure its an int
  }while(again!= 0 && again!=1); //make sure its "0" or "1"
  
  }while(again==1);




  



  inFile.close();
  
  return EXIT_SUCCESS;
}