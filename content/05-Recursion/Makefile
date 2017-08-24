all:	Canon Palindrome TestSimpleSLL

Canon:	Canon.cpp
	g++ -std=c++11 -Wall Canon.cpp -o Canon
	
Palindrome:	Palindrome.cpp
	g++ -std=c++11 -Wall Palindrome.cpp -o Palindrome
	
TestSimpleSLL:	TestSimpleSLL.o SimpleSLL.o
	g++ -std=c++11 -Wall TestSimpleSLL.o SimpleSLL.o -o TestSimpleSLL
	
TestSimpleSLL.o:
	g++ -std=c++11 -Wall -c TestSimpleSLL.cpp
	
SimpleSLL.o:
	g++ -std=c++11 -Wall -c SimpleSLL.cpp
	
clean:
	rm Canon Palindrome TestSimpleSLL