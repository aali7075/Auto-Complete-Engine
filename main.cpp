#include "AutoComplete.h"

int main() {
  AutoComplete * test= new AutoComplete("small_corpus.txt");
  //std::cout << test->CharToInt('b') << '\n';

  // test->Insert("b");
  // std::cout << "In main" << '\n';
  test->Insert("ba");
  TrieNode * yes=test->get_tree();
  if(yes->children[1]->children[0]==NULL){
    std::cout << "Uh oh" << '\n';
  }
  else{
    std::cout << "GANGGANG" << '\n';
  std::cout << (*yes->children[1]) << '\n';
}
int a=0;
std::cout << (char)(a+98) << '\n';

}
