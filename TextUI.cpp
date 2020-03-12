#include "TextUI.h"


/**
TextUI Constructor
Add the menu options. Store inside private variable main_menu_
*/
TextUI::TextUI() {
  // set up the main menu
  main_menu_.push_back("Choose corpus and run engine");
  main_menu_.push_back("Leave");
}

/**
MainMenu()
Shows the options from main menu andd adds a number to it and allows user to select it
If user inputs something illegal continue asking until they input a proper menu option

Return the choice the user made. Will be used as input in RouteChoice
*/

std::string TextUI::MainMenu() {
  int choice = -1;
  while (choice < 0 || choice >= main_menu_.size()) {
    // display the main menu
    for (int i = 0; i < main_menu_.size(); i++) {
      std::cout << std::to_string(i) << ": " << main_menu_[i] << '\n';
    }
    std::string str_choice;
    std::cin >> str_choice;
    try {
      choice = std::stoi(str_choice);
    } catch (const std::invalid_argument& ia) {
      std::cout << "Enter a number" << '\n';
    }
  }
  return main_menu_[choice];
}

bool TextUI::CheckEngineEmpty(AutoComplete * engine){
  bool not_empty=false;
  TrieNode * tree= engine->get_tree();
  for(int i=0; i<26; i++){
    if(tree->children[i]!=NULL){
      not_empty=true;
    }
  }
  return not_empty;

}


/**
RouteChoice() Does approriate action given menu options. In this case there is only
two options Choose corpus and Lave

The choice choose corpus and run engine will:
1. Let user enter a corpus/Textfile
2. Create the search engine by calling AutoComplete on the corpus
3. User inputs the query and gets back search results anc can continue to enter search results
4. Can quit search engine and then either leave or create a new search engine from another corpus

*/

void TextUI::RouteChoice(std::string choice) {
  std::string corpus_name;
  std::string query="";
  std::string choose_response;
  bool choose=true;

  if (choice == "Choose corpus and run engine") {
    std::cout << "Enter the textfile name. Example corpus_name.txt" <<'\n';
    std::cin >> corpus_name;
    AutoComplete * engine= new AutoComplete(corpus_name);//Build AutoComplete engine

    std::cout << '\n' << '\n'<<'\n'<<'\n'; //formatting
    std::cout << "Hello! Welcome to Stateless Autocomplete Engine!" <<'\n';
    choose=this->CheckEngineEmpty(engine);
    if(!choose){
      std::cout << '\n' << '\n'<<'\n'<<'\n'; //formatting
      std::cout << "The AutoComplete engine has no values." <<'\n';
      std::cout << "Perhaps you typed the corpus in wrong. Going back to Main Menu" <<'\n';
      std::cout << '\n' << '\n'<<'\n'<<'\n'; //formatting
    }

    while(choose){ //Let user run specific autocomplete engine until the want to stop
      while(query==""){ //Let user to run multiple queries on autocomplete engine
      std::cout << "Please enter query in the exact form complete,prefix,return_amount" <<'\n';
      std::cout << "Example: complete,ba,1" <<'\n';
      std::cout << '\n' << '\n'<<'\n'; //formatting
      std::cin >> query;
      }
      engine->ParseInput(query);
      engine->PrintResults();
      std::cout << '\n';
      std::cout << "Do you want to continue? Enter Yes or No" << '\n';
      std::cin >> choose_response;
      //make user repsonse all lower_case to reduce errors
      std::transform(choose_response.begin(), choose_response.end(), choose_response.begin(), ::tolower);
      if(choose_response=="no"){
        std::cout << '\n'; //formatting
        std::cout << "Going back to Main Menu" << '\n';
        std::cout << '\n' << '\n'<<'\n'<<'\n'; //formatting
        choose=false;
      }
      else{
        query="";
      }
    }

  }

  else { // Leave option exits the program. Look at main menu to see while loop
    std::cout << "Goodbye! Hope I make it to the final round =)" << '\n';
  }
}
