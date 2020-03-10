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
  std::ifstream file(textfile);
  std::string word;
  while (std::getline(file, word)) {
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    this->Insert(word);
  }
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
    prefix_node=prefix_node->children[CharToInt(prefix[i])]; // go to character
  }
  return prefix_node;
}


void AutoComplete::SearchTree(TrieNode * root){

    if(!root){
      return;
    }

    for(int i=0; i<26; i++){
      if(root->children[i]!=NULL){
        prefix_+=(char)(i+97);
        this->SearchTree(root->children[i]);
      }
    }

    if(root->is_word){
      //std::cout << "Inside is_word if and prefiex_ is " << prefix_<<'\n';
      words_.push_back(std::pair<int,std::string>(root->freq,prefix_));
    }

    prefix_.pop_back(); // popout last letters as we have gone through all its children

    return;


}


void AutoComplete::ParseInput(const std:: string input){
  int comma_count=0;
  std::string value="";
  int input_size=input.size();
  for(int i=9; i<input_size; i++){
    if(input[i]==',' && comma_count==0){
      prefix_=value;
      value="";
      continue;
      }
      value+=input[i];
    }
    number_returns_=stoi(value);
}

void AutoComplete::PrintResults(){
  TrieNode * prefix_node=this->PrefixNode(prefix_);
  this->SearchTree(prefix_node);
  if(words_.empty()){
    std::cout <<'\n';
    return;
  }
  std::sort(words_.begin(), words_.end(), std::greater <>());

  if(words_.size()<number_returns_ || number_returns_==0){
      number_returns_=words_.size();
  }

  for(uint i=0; i<number_returns_-1; i++){
    std::cout << words_[i].second <<", ";
  }
  std::cout << words_[number_returns_-1].second << '\n';

  words_.clear();
  return;
}
