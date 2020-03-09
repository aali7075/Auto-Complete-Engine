#include "AutoComplete.h"


std::ostream& operator<<(std::ostream& os, const TrieNode &node){
  os<<"The node has freq of "<<node.freq<<" ";
  if(node.is_word){
    os<<"and the node is a word"<<'\n';
  }
  else{
    os<<"and the node is not a word"<<'\n';
  }
  return os;
}

AutoComplete::AutoComplete(std::string textfile){
  prefix_tree_= new TrieNode;
  this->CreateNode(prefix_tree_);
  std::cout << (*prefix_tree_) << '\n';
  // std::ifstream file(textfile);
  // std::string word;
  // while (std::getline(file, word)) {
  //   std::transform(word.begin(), word.end(), word.begin(), ::tolower);
  //   std::cout << word << "\n";
  // }
}

void AutoComplete::CreateNode(TrieNode * prefix_node){
  prefix_node->is_word=false;
  prefix_node->freq=0;
  std::cout << "Working?" << '\n';
  for(int i=0; i<26; i++){ //26 because each node has children equal to length of alphabet
    prefix_node->children[i]=NULL;
  }
}

/**
CharToInt is a helper function that returns index for a letter.
It starts with 'a'=0 and ends 'z'=25
*/
int AutoComplete::CharToInt(char letter){
  return (int)letter - 97; //-48 because ascii value of 'a'=97
}

TrieNode AutoComplete::SearchTree(std::string prefix){
  int prefix_length=prefix.size();
  int char_int;
  TrieNode * root=prefix_tree_; //keep track of beginning of prefix tree
  TrieNode return_node;

  for(int i=0; i<prefix_length; i++){
    char_int=this->CharToInt(prefix[i]);
    std::cout << char_int << '\n';
    prefix_tree_=prefix_tree_->children[char_int];
  }
  return_node=(*prefix_tree_);
  prefix_tree_=root;
  return return_node;
}

/**
Search prefix tree to check if word or word part is there if not insert it
*/
// void AutoComplete::Insert(std::string word){
//
//   // Intailzing the size outside of for loop saves compiler time from calling each time
//   int word_size=word.size()
//   std::string build_word
//   for(int i=0; i<=word_size; i++){
//       build_word+=word[i];
//
//   }
// }


// void AutoComplete::Insert(std::string word){
//
//   for
// }
