#include<cstdlib>
#include<ctime>
#include<fstream>
#include<iostream>
#include<string>
#include "HashTable.h"

int main() {
    using namespace std;
    
    srand(time(0));
    
    HashTable<int> intTable;
    HashTable<string> *stringTable = new HashTable<string>(121U);

    for(int i = 0; i < 20; i++) {
        int val = rand() % 100;
        bool inserted = intTable.add(val);
        if(!inserted) {
            cout << "\t*** " << val << " duplicate!" << endl;
        }
    }

    cout << intTable << endl;
    
    HashTable<int> intTable2(intTable);
    cout << endl << intTable2 << endl;
    
    ifstream inFile("words.txt");
    string s;
    while(inFile >> s) {
        bool inserted = stringTable->add(s);
        if(!inserted) {
            cout << "\t*** " << s << " duplicate!" << endl;
        }
    }
    inFile.close();
    
    cout << *stringTable << endl;
    
    cout << "\nSearches:" << endl;
    cout << "\tabrupt:\t" << (stringTable->contains("abrupt") ? "Y" : "N") << endl;
    cout << "\tkitten:\t" << (stringTable->contains("kitten") ? "Y" : "N") << endl;
    cout << "\tvoice:\t" << (stringTable->contains("voice") ? "Y" : "N") << endl;
    
    HashTable<string> stringTable1 = *stringTable;
    
    cout << stringTable1 << endl;
    if(stringTable1.remove("abrupt")) {
        cout << "\n\tremoved abrupt" << endl;
    } else {
        cout << "\n\tdid not remove abrupt" << endl;
    }
    if(stringTable1.remove("kitten")) {
        cout << "\n\tremoved kitten" << endl;
    } else {
        cout << "\n\tdid not remove kitten" << endl;
    }

    cout << stringTable1 << endl;
    
    delete stringTable;
    
    return EXIT_SUCCESS;
}