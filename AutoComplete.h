#ifndef AUTOCOMPLETE_H //create header guards
#define AUTOCOMPLETE_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>

struct TrieNode {
	int freq; //Frequency of the word
  bool is_word;
  TrieNode * children[26]; //26 letters in the alphabet
	// IMPLEMENTED GREATER OVERIDE OPERATOR
	// bool operator==(const Position &other) {
	// 	return row == other.row && col == other.col;
	// }
};

std::ostream& operator<<(std::ostream& os, const TrieNode &node);

class AutoComplete {
  public:

    AutoComplete(std::string textfile);

    void CreateNode(TrieNode * prefix_node);

    int CharToInt(char letter);

    TrieNode SearchTree(std::string prefix);

    void Insert(std::string word);


    void ParseInput(std::string input);

    void PrintResults();





  private:
    TrieNode * prefix_tree_;
    //std::vector<std::pair<int, std::string>> words_;
    int number_returns_;
    std::string prefix_;





};

#endif  // AUTOCOMPLETE_H
