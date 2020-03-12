#ifndef TEXT_UI_H
#define TEXT_UI_H
#include <sstream> // stringstream
#include "AutoComplete.h"


class TextUI {
  public:
    TextUI();

    std::string MainMenu();

    void RouteChoice(std::string choice);

    bool CheckEngineEmpty(AutoComplete * engine);


  private:
    std::vector<std::string> main_menu_;
};


#endif  // TEXT_UI_H
