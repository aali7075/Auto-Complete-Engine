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
  prefix_tree_= this-> CreateNode();
  std::cout << (*prefix_tree_) << '\n';
  // std::ifstream file(textfile);
  // std::string word;
  // while (std::getline(file, word)) {
  //   std::transform(word.begin(), word.end(), word.begin(), ::tolower);
  //   std::cout << word << "\n";
  // }
}

TrieNode * AutoComplete::CreateNode(){
  TrieNode *new_node=new TrieNode;
  new_node->is_word=false;
  new_node->freq=0;
  for(int i=0; i<26; i++){ //26 because each node has children equal to length of alphabet
    new_node->children[i]=NULL;
  }
  return new_node;
}

/**
CharToInt is a helper function that returns index for a letter.
It starts with 'a'=0 and ends 'z'=25
*/
int AutoComplete::CharToInt(char letter){
  return (int)letter - 97; //-97 because ascii value of 'a'=97
}

void AutoComplete::Insert(std::string word){
  int word_length=word.size();
  int char_int;
  TrieNode * current_node=prefix_tree_;

  for(int i=0; i<word_length; i++){
    char_int=this->CharToInt(word[i]);
    if(!current_node->children[char_int]){
    //must create node on child before changing node to child otherwise return_node points to NULL
    current_node->children[char_int]=CreateNode();
    }
    current_node=current_node->children[char_int];
  }
  current_node->freq++;
  current_node->is_word=true;
}



TrieNode * AutoComplete::PrefixNode(std::string prefix){
  int prefix_size= prefix.size();
  TrieNode * prefix_node=prefix_tree_;

  for(int i=0; i<prefix_size; i++){
    if(!prefix_node){ // prefix doesn't exist
      return NULL;
    }
    prefix_node=prefix_node->children[CharToInt(prefix[i])];
  }
  return prefix_node;
}

// //Maybe change toreturn to a leaf node
// bool AutoComplete::CheckLeaf(TrieNode * tree_node){
//
//   for(int i=0; i<26 i++;){
//     if(!tree_node->children[i]){
//       return true;
//     }
//   }
//   return false;
//
// }

/**
Searches for the prefix and then uses dfs via recursion to grab all values
*/

std::vector<std::pair<int,std::string>> AutoComplete::SearchTree(TrieNode * root, std:: string word_build){
  TrieNode * search_node=root;
  bool check_null;
    for(int i=0; i<26; i++){
      if(!root->children[i]){
        word_build+=(char)(i+97);
        root=root->children[i];
        if(root->is_word){
          words_.append(std::pair<int,std::string>(root->freq,word_build));
        }
      }
    }
    return;

  return words;


}
