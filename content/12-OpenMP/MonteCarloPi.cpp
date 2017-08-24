#include <chrono>
#include <cstdlib>
#include <iostream>
#include <omp.h>
#include <random>

int uniCount(int n) {
	using namespace std;
	
	int numIn = 0;		// number in the circle
	long double x, y;	// coordinates for each dart

	// Mersenne Twister prng, and a distribution to create numbers in [-1, 1)
	mt19937 prng(chrono::system_clock::now().time_since_epoch().count());
	uniform_real_distribution<long double> dis(-1.0, 1.0);

	// throw n darts
	for (int i = 0; i < n; i++) {
		x = dis(prng);
		y = dis(prng);

		// if the dart is in the circle, count it
		if ((x * x + y * y) <= 1.0) {
			numIn++;
		} // if

	} // for n
	return numIn;
}

int parallelCount(int n) {
	using namespace std;
	
	int numIn = 0;

// begin parallel section. numIn is a multi-thread accumulator
#pragma omp parallel reduction(+:numIn) 
{
	// variables declared inside the parallel section are local to each
	// thread. The Mersenne Twister prng isn't thread-safe, so we need it
	// and the distribution here
	long double x, y;	// coordinates for each dart

	// Mersenne Twister prng, and a distribution to create numbers in [-1, 1)
	mt19937 prng(chrono::system_clock::now().time_since_epoch().count());
	uniform_real_distribution<long double> dis(-1.0, 1.0);

#pragma omp for
	// throw n darts
	for (int i = 0; i < n; i++) {
		x = dis(prng);
		y = dis(prng);

		// if the dart is in the circle, count it
		if ((x * x + y * y) <= 1.0) {
			numIn++;
		} // if
	} // for n

} // parallel section
	
	
	return numIn;
}

/**
 * Multi-threaded program to estimate the value of pi, using a Monte Carlo 
 * process.Imagine a circle with radius 1, centered at the origin of a cartesian 
 * plane, insribed within a square with sides of length 2. Throw n random 
 * "darts" --random points with each(x, y) in the range[-1, 1] --at this dart 
 * board. Count the number of darts that are inside the circle, then compute 
 * 4 * in / n; this is the estimated value of pi.
 * 
 * Usage: MonteCarloPi [s|p] n
 * 
 * \param iArgC Number of command-line arguments passed in
 * \param ppszArgV Array of C strings holding command-line arguments
 */
int main(int iArgC, char** ppszArgV) {
	
	using namespace std;
	
	// single processor or parallel?
	char sOrP = ppszArgV[1][0];

	// number of "darts" to throw
	int n = atoi(ppszArgV[2]);

	// number of "darts" that landed in the circle
	int numIn = 0;

	chrono::time_point<chrono::system_clock> start, end;
	
	start = chrono::system_clock::now();
	if(sOrP == 's') {
		numIn = uniCount(n);
	} else {
		numIn = parallelCount(n);
	}
	end = chrono::system_clock::now();
	
	chrono::duration<double> elapsed = end - start;
	
	// create estimate
	long double myPi = 4.0 * numIn / n;

	// output results
	if(sOrP == 's') {
		cout << "Using one thread..." << endl;
	} else {
		cout << "Using " << omp_get_max_threads() << " threads..." << endl;
	}
	cout << "Estimate = " << myPi << endl;
	cout << "Elapsed time = " << elapsed.count() << " s" << endl;

	return EXIT_SUCCESS;
}