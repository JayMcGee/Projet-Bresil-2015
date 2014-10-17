all: TestUart

TestUart: TestUart.o BlackUART.o BlackCore.o
	g++ -std=c++0x TestUart.o BlackUART.o BlackCore.o -o MainTest
	
TestUart.o: TestUart.cpp
	g++ -std=c++0x -c TestUart.cpp
	
BlackUART.o: ../BlackLib/BlackUART.cpp
	g++ -std=c++0x -c ../BlackLib/BlackUART.cpp

BlackCore.o: ../BlackLib/BlackCore.cpp
	g++ -std=c++0x -c ../BlackLib/BlackCore.cpp
	
clean: rm *.o
		rm MainTest

