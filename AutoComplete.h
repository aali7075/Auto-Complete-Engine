#ifndef AUTOCOMPLETE_H //create header guards
#define AUTOCOMPLETE_H
#include <iostream>
#include <string>
#include <vector>

// struct TrieNode {
// 	std::string word;
// 	int freq; //Frequency of the word
//   bool is_word;
//   std::vector< TrieNode *> children;
//
// 	// IMPLEMENTED GREATER OVERIDE OPERATOR
// 	// bool operator==(const Position &other) {
// 	// 	return row == other.row && col == other.col;
// 	// }
// };

class AutoComplete {
  public:
    AutoComplete(std::string word);


  private:
    TrieNode prefix_tree_;
    std::vector<int, std::string> words_;
    int number_returns_;
    std::string prefix_;





};

#endif  // AUTOCOMPLETE_H
