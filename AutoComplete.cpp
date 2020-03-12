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


/**
AutoComplete() Constructor
parameters: Textfile is the corpus
Take each word from corpus and insert word into prefix tree
*/
AutoComplete::AutoComplete(std::string textfile){
  prefix_tree_= this-> CreateNode(); //Intializes the prefix_tree
  std::ifstream file(textfile);
  std::string word;
  while (std::getline(file, word)) {
    std::transform(word.begin(), word.end(), word.begin(), ::tolower); //make each word all lower case
    this->Insert(word);
  }
}


/**
CreateNode() creates a new TrieNode
 Sets the is_word intially to false. is_word is checked in Insert function
 all children are set to NULL intially since it is a new node
 returns: the new_node that will replace a NULL child node in the prefix_tree
*/

TrieNode * AutoComplete::CreateNode(){
  TrieNode *new_node=new TrieNode;
  new_node->is_word=false;
  new_node->freq=0; //starts at 0 since it is a new node
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

/**
Insert() takes one word at a time and places them into prefix tree
parameters: word is a word read in from the corpus

Take the word and seperate it into its letters. Traverse through the tree
and go to a deeper level for each letter. If the letter at correpsonding letter
depth is not created create the node.
After traversing entire word increase the last letter node
freq by 1 and set is_word to true

*/

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


/**
PrefixNode() takes one word at a time and places them into prefix tree
parameters: prefix is the prefix the user inputs. The prefix will always be stored in the
private prefix_ variable

Checks to see it the node corresponding to the prefix string is there. If it is
return it. The prefix node will be used as the starting node for SearchTree method.

*/


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

/**
SearchTree() Uses Recursion to go thorough the tree starting at the prefix node.
Uses DFS.

Parameters: root is the prefix_node using the method prefix_node

Searches through each child node and if child node exist then we recall the search tree.
Once all children have been searched check if node is a word if it is then add
the word Frequency and word to a the private variable words_ then go back the parent node
and repeat
*/

void AutoComplete::SearchTree(TrieNode * root){

    if(!root){ // If prefix node is not there then we don't search
      return;
    }

    for(int i=0; i<26; i++){ //26 because size of alphabet
      if(root->children[i]!=NULL){
        prefix_+=(char)(i+97); // ascii value of 'a'= 97 so if i=0 then prefix_ appends 'a'
        this->SearchTree(root->children[i]);//Recurse with child as new root
      }
    }

    if(root->is_word){
      words_.push_back(std::pair<int,std::string>(root->freq,prefix_));
    }

    prefix_.pop_back(); // popout last letters as we have gone through all its children

    return;


}

/**
ParserInput() Takes the user input string and parses it and store the prefix in the
private variable prefix_ and stores the number of search returns in private variable number_returns_

Parameters: input the string that the users typed which should be "complete,prefix,num"

*/

void AutoComplete::ParseInput(const std:: string input){
  int comma_count=0;
  std::string value="";
  int input_size=input.size();
  for(int i=0; i<input_size; i++){
    if(input[i]==',' && comma_count==0){ //store prefix after the first comma has been found
      prefix_=value;
      value=""; // Change value back to empty to then store the number
      continue;
      }
      value+=input[i];
    }
    //convert value from string to int and store inside private variable number_returns_
    number_returns_=stoi(value);
}

/**
PrintResults() Prints out the words that has the prefix given and prints out the
amount given by number_returns_;

Calls on the methods PrefixNode to get the starting search Position. Then calls
searchTree which then populates the private variable words_ with the autocomplete words
If no prefix is given or prefixNode is empty program will print an empty line.
Then sort words_ by frequency and print out the amount of results specified by user.
Note if user ask for more results then amount of words or inputs 0 return all words in words_

*/
void AutoComplete::PrintResults(){
  std::string prefix_check;

  if(prefix_==""){ // If no prefix is given output new line and return nothing
    std::cout <<'\n';
    return;
  }

  TrieNode * prefix_node=this->PrefixNode(prefix_);
  prefix_check=prefix_;
  this->SearchTree(prefix_node);

  for(int i=0; i<words_.size(); i++){// erase the prefix from the vector words_
    if(words_[i].second==prefix_check){
      words_.erase(words_.begin()+i);
    }
  }

  if(words_.empty()){//prefix node has only NULL as children i.e no words below it
    std::cout <<'\n';
    return;
  }
  //sort the private vector words_ based on freq that has the results from search
  //std::greater <>()  needed to sort words from descending order
  std::sort(words_.begin(), words_.end(), std::greater <>());

  //user ask for more results than words or inputs 0
  if(words_.size()<number_returns_ || number_returns_==0){
      number_returns_=words_.size();
  }

  for(uint i=0; i<number_returns_-1; i++){//End before last element for proper formatting
    std::cout << words_[i].second <<", ";
  }
  std::cout << words_[number_returns_-1].second << '\n';

  words_.clear();//Clear words after search result to save space
  return;
}
