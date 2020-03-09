#include "AutoComplete.h"

int main() {
AutoComplete * test= new AutoComplete("small_corpus.txt");
std::cout << test->CharToInt('b') << '\n';

}
