#include "SimpleSLL.h"
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <ctime>

/**
 * Program to generate poem with a user specified number of lines, and words.
 * The poem is made up of words randomly chosen from a list.
 * The list is filled with words added from a dictionary.txt file.
 * 
 * 
 * \authors <Charley Burtwistle, Chase Stone>
 * \date <September 6, 2017>
 */


//-----------------------------------------------------------
// Body of code (what is executed when called from the command line)
//-----------------------------------------------------------



int main() {
  

  using namespace std;

  SimpleSLL list;
  
  
  //seed the rand, randomly
  srand(time(0));
  
  cout <<"Welcome to the random poetry generator!" <<
         "Please wait while the dictiionary is loaded. \n" << endl;
  
  //open input file
  ifstream inFile;
  inFile.open("dictionary.txt");
  
  //add all the files to the list
  string all ;
  while( inFile >> all){
    list.add(all);
  }
  
  //create a flag to determine if the user wants to run it again
  int again = 1;
  
  //enter a do/while which the user will run through each time they want to create a poem
  do{
    

  //get the number of lines from the user
  int lines;
  cout << "Let's make some poetry, dude! Enter the number of lines:";
  cin >> lines;
  
  //error handling in case the user doesn't follow directions
  while (cin.fail()) { // if the user doesn't enter an int
    cout << "Please Enter an int." << std::endl; //inform them that they messed up
    cin.clear(); //clear the error flag on cin (i.e. cin.fail())
    cin.ignore(256,'\n'); //ignore 256 characters that the user inputed, or until a '\n' is reached (aka everything before the user hit "enter")
    cin >> lines; //try again
}
    

  //get the number of words
  int words;
  cout << "Radical! Now, enter the number of words per line: ";
  cin >> words;
  
  //same error handling as before
  while (cin.fail()) {
  cout << "Please Enter an int." << std::endl;
  cin.clear();
  cin.ignore(256,'\n');
  cin >> words;
    }
  
  //output the poem
  cout << "\nHere's your poem man: \n" << endl;
  for (int i = 0; i<lines; i++){
    for (int j = 0; j<words; j++){
        cout << list.getRandom() << " ";
      
    }
    cout << "\n";
  }

  
  //enter a do/while to make sure the user says 1 or 0
  do{
  cout << "\nWould you like to make another poem? Enter 1 for yes, 0 for no: ";
  cin >> again;
  //same error handling
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