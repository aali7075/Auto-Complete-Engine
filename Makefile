CXX = g++
CXXTESTFLAGS = --coverage #for unit testing
CXXFLAGS = -std=c++17 -Wall

all: main test

clean:
	rm main AutoComplete.o TextUI.o test


main: main.cpp AutoComplete.o TextUI.o
	$(CXX) $(CXXFLAGS) main.cpp AutoComplete.o TextUI.o -o main

AutoComplete.o: AutoComplete.cpp
	$(CXX) $(CXXFLAGS) -c AutoComplete.cpp

TextUI.o: TextUI.cpp
	$(CXX) $(CXXFLAGS) -c TextUI.cpp

test: AutoComplete.o test.cpp
	$(CXX) $(CXXFLAGS) test.cpp AutoComplete.o -o test
