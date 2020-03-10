#include "TextUI.h"
//#include "AutoComplete.h"

int main() {

  // Create a TextUI object, then continue prompting the user
  // for what they want to do until they leave the store
  std::string query="complete ,b,0";
  query.erase(remove(query.begin(), query.end(), ' '), query.end());
  std::cout << "Query is " << query<<'\n';
  TextUI ui;
  std::string choice;
  while (choice != "Leave") {
    choice = ui.MainMenu();
    std::cout << '\n';
    ui.RouteChoice(choice);
  }
  //AutoComplete * test= new AutoComplete("small_corpus.txt");
  //std::cout << test->CharToInt('b') << '\n';

  // test->Insert("b");
  // std::cout << "In main" << '\n';
//   test->Insert("ba");
//   TrieNode * yes=test->get_tree();
//   if(yes->children[1]->children[0]==NULL){
//     std::cout << "Uh oh" << '\n';
//   }
//   else{
//     std::cout << "GANGGANG" << '\n';
//   std::cout << (*yes->children[1]) << '\n';
// }
// int a=0;
// std::cout << (char)(a+98) << '\n';

  // std::cout << "PREFIX NOT THERE!!!!!!!!!!!" << '\n';
  //
  // TrieNode * prefix_node=test->PrefixNode(""); //check for this test case
  // if(!prefix_node){
  //   std::cout << "This is empty bruh" << '\n';
  // }
  //
  //
  //
  // for(uint i=0; i<maybe.size(); i++){
  //   std::cout << maybe[i].second << '\n';
  // }
  // std::sort(maybe.begin(), maybe.end(), std::greater <>() );
  // std::cout << "AFTER SORTING" << '\n';
  // for(uint i=0; i<maybe.size(); i++){
  //   std::cout << maybe[i].second << '\n';
  // }
  //
  // test->ParseInput("complete,be,1");
  // test->ParseInput("complete,ba,3");
  // test->PrintResults();
  //
  // test->ParseInput("complete,ba,2");
  // prefix_node=test->PrefixNode("ba");
  // test->SearchTree(prefix_node);
  // test->PrintResults();
  //
  // test->ParseInput("complete,be,3");
  // prefix_node=test->PrefixNode("be");
  // test->SearchTree(prefix_node);
  // test->PrintResults();
  //
  // test->ParseInput("complete,b,0");
  // prefix_node=test->PrefixNode("b");
  // test->SearchTree(prefix_node);
  // test->PrintResults();




}
