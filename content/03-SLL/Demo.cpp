#include <cstdlib>
#include <ctime>
#include <iostream>
#include "SLL.h"

int main() {
    using namespace std;
    srand(time(0));
    
    SLL<double> list;
    
    for(int i = 0; i < 10; i++) {
        double d = rand() / ((double)RAND_MAX);
        list.add(d);
    }
    
    cout << list << endl;
    
    for(SLL<double>::Iterator i = list.begin(); i != list.end(); ++i) {
        *i *= 2;
    }
    
    cout << list << endl;
    
    return EXIT_SUCCESS;
}