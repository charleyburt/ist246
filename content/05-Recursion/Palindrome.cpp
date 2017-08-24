#include <cstdlib>
#include <iostream>
#include <string>

/*
 * Determining if strings input from the keyboard are palindromes,
 * using recursion.
 */

//-----------------------------------------------------------
// forward definitions for functions
//-----------------------------------------------------------

/**
 * Determine if a string is a palindrome or not.
 *
 * \param s String to check for palindrome-ness.
 */
bool isPalindrome(const std::string &s);

/**
 * Recursive helper function for isPalindrome().
 *
 * \param s String to check for palindrome-ness.
 * \param i Leftmost index of region of s to check.
 * \param j Rightmost index of region of s to check.
 */
bool isPalindrome(const std::string &s, int i, int j);

//-----------------------------------------------------------
// function implementations
//-----------------------------------------------------------

/**
 * Application entry point.
 */
int main() {
  using namespace std;

  string s;

  cout << "Enter a string, or Q to quit: ";
  cin >> s;

  while (s != "Q") {
    cout << s << (isPalindrome(s) ? " is" : " is not") << " a palindrome."
         << endl;

    cout << "Enter a string, or Q to quit: ";
    cin >> s;
  }

  cout << "Thanks for playing!" << endl;

  return EXIT_SUCCESS;
}

/*
 * Implementation of the isPalindrome() function.
 */
bool isPalindrome(const std::string &s) {
  // call the recursive helper with widest possible area to
  // examine
  return isPalindrome(s, 0, s.size() - 1);
}

/*
 * Implementation of the recursive isPalindrome() helper function.
 */
bool isPalindrome(const std::string &s, int i, int j) {
  // base case: left and right indices have overlapped? If so,
  // s is a palindrome
  if (j <= i) {
    return true;
  }
  // second base case: if characters at i and j aren't equal, s
  // is NOT a palindrome
  else if (s[i] != s[j]) {
    return false;
  }
  // general case: move each index inwards by one character
  else {
    return isPalindrome(s, i + 1, j - 1);
  }
}
