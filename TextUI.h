#ifndef TEXT_UI_H
#define TEXT_UI_H
#include <sstream> // stringstream
#include "AutoComplete.h"

/**
  Provided code for CSCI 3010, PE 7, Fall 2019
*/

class TextUI {
  public:
    TextUI();

    std::string MainMenu();

    void RouteChoice(std::string choice);

    //std::string QueryCheck(std::string query);



  private:
    std::vector<std::string> main_menu_;
};


#endif  // TEXT_UI_H
