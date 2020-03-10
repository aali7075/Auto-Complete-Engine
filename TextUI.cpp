#include "TextUI.h"

TextUI::TextUI() {
  // set up the main menu
  main_menu_.push_back("Choose corpus and run engine");
  //main_menu_.push_back("Autocomplete Engine");
  main_menu_.push_back("Leave");
}

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

// std::string TextUI::QueryCheck(std::string query){
//   std::string q_copy=query;
//   std::string spelling="";
//   q_copy.erase(remove(q_copy.begin(), q_copy.end(), ' '), q_copy.end());
//   std::cout << "q_copy is " << q_copy<<'\n';
//   std::transform(q_copy.begin(), q_copy.end(), q_copy.begin(), ::tolower);
//   std::cout << "q_copy is " << q_copy<<'\n';
//   for(int i=0; i<9; i++){
//     spelling+=q_copy[i];
//   }
//
//   if(spelling!="complete,"){
//     return "";
//   };
//   return q_copy;
//
//
// }

void TextUI::RouteChoice(std::string choice) {
  std::string corpus_name;
  std::string query="";
  std::string choose_response;
  bool choose=true;

  if (choice == "Choose corpus and run engine") {
    std::cout << "Enter the textfile name. Example corpus_name.txt" <<'\n';
    std::cin >> corpus_name;
    AutoComplete * engine= new AutoComplete(corpus_name);

    std::cout << "Hello! Welcome to Stateless Autocomplete Engine!" <<'\n';

    while(choose){
      while(query==""){
      std::cout << "Please enter query in the exact form complete,prefix,return_amount" <<'\n';
      std::cout << "Example: complete,ba,1" <<'\n';
      std::cout << '\n' << '\n'<<'\n';
      std::cin >> query;
      }
      engine->ParseInput(query);
      engine->PrintResults();
      std::cout << '\n' << '\n';
      std::cout << "Do you want to continue? Enter Yes or No" << '\n';
      std::cin >> choose_response;
      std::transform(choose_response.begin(), choose_response.end(), choose_response.begin(), ::tolower);
      if(choose_response=="no"){
        choose=false;
      }
      else{
        query="";
      }
    }

  }
  // else if (choice == "Autocomplete Engine") {
  //   std::cout << "Hello! Welcome to Stateless Autocomplete Engine!" <<'\n';
  //
  //   while(choose){
  //     while(query==""){
  //     std::cout << "Please enter query in the form complete,prefix,return_amount" <<'\n';
  //     std::cout << "Example: complete,ba,1" <<'\n';
  //     std::cin >> query;
  //     query=QueryCheck(query);
  //     }
  //     std::cout << "query is " << query<<'\n';
  //     engine->ParseInput(query);
  //     std::cout << "Working?" << '\n';
  //     engine->PrintResults();
  //     std::cout << "Do you want to continue? Enter Yes or No" << '\n';
  //     std::cin >> choose_response;
  //     std::transform(choose_response.begin(), choose_response.end(), choose_response.begin(), ::tolower);
  //     if(choose_response=="no"){
  //       choose=false;
  //     }
  //   }
  // }
  else {
    std::cout << "Goodbye! Hope I make it to the final round =)" << '\n';
  }
}
