#include <cstdlib>
#include <iostream>

/*
 * Several of the "canonical" introductory examples for learning
 * about recursion: power, factorial, and Fibonacci numbers.
 */

//-----------------------------------------------------------
// forward definitions for functions
//-----------------------------------------------------------

/**
 * Recursively compute the factorial of an integer.
 *
 * \param n Value to compute n! for
 * \return n!, as an unsigned long
 */
unsigned long fact(unsigned long n);

/**
 * Recursively compute the nth Fibonacci number.
 *
 * \param n Which Fibonacci number?
 * \return The nth Fibonacci number
 */
unsigned long fib(unsigned n);

/**
 * Recursively compute the ith power of a number.
 *
 * \param x base value
 * \param i power to raise the base to
 * \return x^i
 */
int power(int x, unsigned i);

//-----------------------------------------------------------
// function implementations
//-----------------------------------------------------------

/**
 * Application entry point.
 */
int main() {
  using namespace std;

  cout << "***** Testing factorial:" << endl;

  for (unsigned long i = 1ul; i <= 20ul; i++) {
    cout << "\t" << i << "! =\t" << fact(i) << endl;
  }

  cout << "\n\n***** Testing power:" << endl;

  for (unsigned i = 0u; i <= 10u; i++) {
    cout << "\t2^" << i << " =\t" << power(2, i) << endl;
  }

  cout << "\n\n***** Testing Fibonacci:" << endl;

  for (unsigned i = 1u; i <= 45u; i++) {
    cout << "\tFib(" << i << ") = " << fib(i) << endl;
  }

  return EXIT_SUCCESS;
}

/*
 * Implementation of the recursive factorial function.
 */
unsigned long fact(unsigned long n) {
  if (n <= 1ul) {
    return 1;
  } else {
    return n * fact(n - 1ul);
  }
}

/*
 * Implementation of the recursive Fibonacci number function.
 */
unsigned long fib(unsigned n) {
  if (n == 1u || n == 2u) {
    return 1ul;
  } else {
    return fib(n - 1u) + fib(n - 2u);
  }
}

/*
 * Implementation of the recursive power function.
 */
int power(int x, unsigned i) {
  if (i == 0u) {
    return 1;
  } else {
    return x * power(x, i - 1);
  }
}
