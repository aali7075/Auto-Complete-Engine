CXX = g++
CXXTESTFLAGS = --coverage #for unit testing
CXXFLAGS = -std=c++17 -Wall

all: main

clean:
	rm main


main: main.cpp AutoComplete.o
	$(CXX) $(CXXFLAGS) main.cpp AutoComplete.o -o main

AutoComplete.o: AutoComplete.cpp
	$(CXX) $(CXXFLAGS) -c AutoComplete.cpp

# TextUI.o: TextUI.cpp
# 	$(CXX) $(CXXFLAGS) -c TextUI.cpp

# test: test.cpp
# 	$(CXX) $(CXXFLAGS) test.cpp -o test
