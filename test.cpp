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
  TrieNode * med_tree=med_engine->get_tree();

  SECTION("small_corpus"){
    REQUIRE(small_tree!=NULL);
    REQUIRE(small_tree->freq==0);
    REQUIRE(small_tree->is_word==false);

  }
  SECTION("medium_corpus"){
    REQUIRE(med_tree!=NULL);
    REQUIRE(med_tree->freq==0);
    REQUIRE(med_tree->is_word==false);
  }

}


TEST_CASE ( "AutoComplete CreateNode") {
  TrieNode * small_tree=small_engine->get_tree();
  TrieNode * med_tree=med_engine->get_tree();
  small_tree->children[25]=small_engine->CreateNode();
  med_tree->children[25]= med_engine->CreateNode();


  SECTION("small_corpus"){
    REQUIRE(small_tree->children[25]!=NULL);
    REQUIRE(small_tree->children[25]->freq==0);
    REQUIRE(small_tree->children[25]->is_word==false);
    REQUIRE(small_tree->children[25]->children[0]==NULL);


  }
  SECTION("medium_corpus"){
    REQUIRE(med_tree->children[25]!=NULL);
    REQUIRE(med_tree->children[25]->freq==0);
    REQUIRE(med_tree->children[25]->is_word==false);
    REQUIRE(med_tree->children[25]->children[0]==NULL);
  }

}

TEST_CASE ( "AutoComplete Insert") {
  small_engine->Insert("z");
  med_engine->Insert("zo");
  TrieNode * small_tree=small_engine->get_tree();
  TrieNode * med_tree=med_engine->get_tree();

  SECTION("small_corpus"){
    REQUIRE(small_tree->children[25]!=NULL);
    REQUIRE(small_tree->children[25]->freq==1);
    REQUIRE(small_tree->children[25]->freq==1);
    REQUIRE(small_tree->children[25]->is_word==true);

  }
  SECTION("medium_corpus"){
    REQUIRE(med_tree->children[25]!=NULL);
    REQUIRE(med_tree->children[25]->freq==0);
    REQUIRE(med_tree->children[25]->is_word==false);
  }

}

TEST_CASE ( "AutoComplete ParseInput") {
  small_engine->ParseInput("complete,ba,3");
  med_engine->ParseInput("complete,aa,5");

  std::string small_prefix= small_engine->get_prefix();
  int small_num_ret=small_engine->get_number_returns();

  std::string med_prefix= med_engine->get_prefix();
  int med_num_ret=med_engine->get_number_returns();

  SECTION("small_corpus"){
    REQUIRE(small_prefix=="ba");
    REQUIRE(small_num_ret==3);

  }
  SECTION("medium_corpus"){
    REQUIRE(med_prefix=="aa");
    REQUIRE(med_num_ret==5);
  }

}

TEST_CASE ( "AutoComplete Search") {
  TrieNode * prefix_node=small_engine->PrefixNode("ba");
  small_engine->ParseInput("complete,ba,2");
  small_engine->SearchTree(prefix_node);

  std::vector<std::pair<int, std::string>> words_= small_engine->get_words();

  std::sort(words_.begin(), words_.end(), std::greater <>());

  std::vector<std::pair<int, std::string>> test{{2,"bat"},{1,"bark"},{1,"bar"}};



  SECTION("small_corpus"){
    REQUIRE(words_== test);
    REQUIRE(words_[0]==test[0]);
    REQUIRE(words_[1]==test[1]);
    REQUIRE(words_[2]==test[2]);
  }


}
