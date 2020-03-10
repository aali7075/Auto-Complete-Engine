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

    TrieNode * CreateNode();

    int CharToInt(char letter);

    void SearchTree(TrieNode *root);

    TrieNode * PrefixNode(std::string prefix);

    void Insert(std::string word);


    void ParseInput(const std::string input);

    void PrintResults();

    TrieNode * get_tree(){return prefix_tree_;};

		std::vector<std::pair<int, std::string>> get_words(){return words_;};
		void set_prefix(std::string word){prefix_=word;};


  private:
    TrieNode * prefix_tree_;
    std::vector<std::pair<int, std::string>> words_;
    int number_returns_;
    std::string prefix_;





};

#endif  // AUTOCOMPLETE_H
