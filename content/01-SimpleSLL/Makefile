TestSimpleSLL:	SimpleSLL.o TestSimpleSLL.o
	g++ -std=c++11 -Wall -ggdb SimpleSLL.o TestSimpleSLL.o -o TestSimpleSLL

SimpleSLL.o:	SimpleSLL.cpp
	g++ -std=c++11 -Wall -ggdb -c SimpleSLL.cpp

TestSimpleSLL.o:	TestSimpleSLL.cpp
	g++ -std=c++11 -Wall -ggdb -c TestSimpleSLL.cpp

clean:
	rm *.o TestSimpleSLL