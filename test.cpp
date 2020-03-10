/**
Aaron Li
*/

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "AutoComplete.h"

AutoComplete * small_engine= new AutoComplete("small_corpus.txt");
AutoComplete * med_engine= new AutoComplete("medium_corpus.txt");

TEST_CASE ( "AutoComplete Constructor") {
  TrieNode * small_tree=small_engine->get_tree();
  TrieNode * medium_tree=med_engine->get_tree();

  SECTION("small_corpus"){
    REQUIRE(small_tree!=NULL);
    REQUIRE(small_tree->freq==0);
    REQUIRE(small_tree->is_word==false);

  }
  SECTION("medium_corpus"){
    REQUIRE(medium_tree!=NULL);
    REQUIRE(medium_tree->freq==0);
    REQUIRE(medium_tree->is_word==false);
  }

}


TEST_CASE ( "AutoComplete Insert") {
  small_engine->Insert("z");
  med_engine->Insert("zoo");
  TrieNode * small_tree=small_engine->get_tree();
  TrieNode * medium_tree=med_engine->get_tree();

  SECTION("small_corpus"){
    REQUIRE(small_tree->children[25]!=NULL);
    REQUIRE(small_tree->children[25]->freq==1);
    REQUIRE(small_tree->children[25]->freq==1);
    REQUIRE(small_tree->children[25]->is_word==true);

  }
  SECTION("medium_corpus"){
    REQUIRE(medium_tree->children[25]!=NULL);
    REQUIRE(medium_tree->children[25]->freq==0);
    REQUIRE(medium_tree->children[25]->is_word==false);
  }

}


// TEST_CASE ( "Count specfic key") {
//   Counter <int> * int_map= new Counter(ints);
//   Counter <std::string> * animals_map= new Counter(animals);
//   Counter <char> * char_map= new Counter(chars);
//   Counter <double> * double_map= new Counter(dub);
//   Counter <bool> * bool_map= new Counter(bools);
//   SECTION("Using ints"){
//     REQUIRE(int_map->Count(1)==3);
//   }
//   SECTION("Using strings"){
//     REQUIRE(animals_map->Count("cat")==2);
//   }
//   SECTION("Using char"){
//     REQUIRE(char_map->Count('a')==3);
//   }
//   SECTION("Using double"){
//     REQUIRE(double_map->Count(3.0)==2);
//   }
//   SECTION("Using bool"){
//     REQUIRE(bool_map->Count(true)==3);
//   }
//
// }
