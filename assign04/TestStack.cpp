#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "Stack.h"

/**
 * 
 * The program evaluates postfix arithmetic expressions containing
 * real numbers and the operators +, -, *, and /.
 * 
 * 
 * \authors <Charley Burtwistle, Brian Spencer>
 * \date <September 27, 2017>
 */


//-----------------------------------------------------------
// Body of code (what is executed when called from the command line)
//-----------------------------------------------------------




int main() {
  using namespace std;

  // Create Stack
  Stack<int> stack;
  
  // Create String
  string token;

  //Welcome the User and explain rules
  cout << "Welcome to the Doane RPN Calculator!" << endl; 
  cout << "Please enter an expression in postfix, EOF(Ctrl+D in the Cloud9 terminal) to quit" << endl; 

  // go through what they entered, using the " " as a delimiter 
  while(cin >> token){

    // if it is division
    if (token == "/"){
      
      //get top two elements (pop also removes them, so we need not worry about clearing the stack)
      double first = stack.pop();
      double second = stack.pop();
      
      // perform the operation
      double next= second / first;
      
      //push the results
      stack.push(next);

    }
    
    //Similar logic as division follows
    else if (token == "*"){
      double first = stack.pop();
      double second = stack.pop();
      
      double next= second * first;
      
      stack.push(next); 
    }
    
    else if (token == "+"){
      double first = stack.pop();
      double second = stack.pop();
      
      double next= second + first;
      
      stack.push(next); 
    }    

    else if (token == "-"){
      double first = stack.pop();
      double second = stack.pop();
      
      double next= second - first;
      
      stack.push(next); 
    }
    
    //the user ends every expression with "E" so this will pop what is left (i.e. the answer)
    else if (token == "E"){
      
      cout << stack.pop() << endl;

    }
    
    //every time the program encounters a double it pushes it to the top of the stack
    else{
      double val = atof(token.c_str());
      stack.push(val);      
    }
    
  }
  
  //once the user enters the EOF character it ends the while loop (i.e. the program) 
  cout << "Goodbye!" << endl;
  
  return EXIT_SUCCESS;
}
