# Auto-Complete Engine
## Created by Aaron Li

### Design Choices

#### Coding style
I follow the CPP Core Guidlines style. 
Functions, classes, and data structures are always have each word capitalized with no space Ex: AutoComplete()

private variables always end with a _. Ex: words_

local variables will always be lowercase and words will be sperated by spaces. Ex: is_num

Functions always have a function comment before the function that describes the function and what parameters it takes in.

#### Data structures
For this problem. I decided to use create prefix tree also known as a trie. A trie is a data structure that starts with a root node. Each node has 3 attributes. The first attribute freq stores how many times the word appears in the corpus. The second attritbute is a bool datatype is_word that flags if the current node is a builds up to a word.The third attribute is an array of 26 children nodes where each node represents a letter in english alphabet. 

I chose a Trie over other methods such as a hash table, or binary search because it is effiecient in terms of space and time complexity. A hash table can store a each possible prefix as a key and store the values as its corresponding autocomplete words. This gives us a theortical O(1) search time but the space complexity is O(N*N*M) where N is the length of suggestions and M is the string. This can become very expensive it terms of space very fast. Binary seach takes O(N) and O(log(N)) look up time. The problem with this is that you need to sort through the entire dictionary, which takes O(nlog(n)) time originally, which can be very time-consuming at the beginning; furthermore, there is a lot of unnecessary space wasted since many words have the same prefix.

A trie is the best in terms of balancing space and time complexity. It saves space by store words with the space prefix on the same path. This means it scales well as the corpus increasing compared to a binary search or a hash table. In uses, depth-first search to grab all the values O(V+ E) where V is all the nodes from the starting edge to and E is all of the edges. This may seem like a long time, but it is much faster when we consider the fact that the starting node i.e the prefix node, can be found in  O(P) time where P is the length of the word. Our search tree then becomes exponentially smaller. The prefix becomes larger, which is great since, in the real world, most people have a word in mind when they are looking at autocomplete. After searching through the words, I then place them inside of an array and sort the array based on the frequency of the word to show the most frequent word first, which takes O(nlogn) of the search tree. As mentioned before, as the prefix becomes larger, the tree becomes exponentially smaller, so in most cases, it is not much computation.

#### Classes
I created a class called AutoComplete for the search, Insert, Sorting methods inside of a class because it is more organized and makes it more readable for the another programmer. In addtion, each class is sperated into its own h and cpp file to make it more readable

### Testing
For testing I used mostly unit testing with the Catch2 framework. I created unit tests for two different Autocomplete engines. I tested each method to see if it worked properly. This allowed me to check if my code was working much faster than if I manually checked my own answers.

### Improving
If I had more time, I would improve on two things. First, I would improve my prefix tree so that it becomes a Deterministic Finite Automata (DFA). A prefix tree is a special case of a DFA with the difference begin that a DFA saves even more space by taking shared suffixes of words and pointing them in the same place. This makes memory complexity much smaller while still maintaing the same time complexity.


## How to run the code

### Makefile
I have created a makefile to make compiling much simpler. A makefile is also more system independent, which causes fewer bugs. Currently, my make file creates tow programs. First is the main program, which holds the actual program, and the second is the test program, which has all of the unit testings on it. To compile the main program and the test program, please type in terminal:
**make** 
to compile only the main program type in the terminal
**make main**
To run the main program, please type in the terminal:
**./main**
Likewise, to run the unit test type in
**./test**

### Text UI

I have implemented a TextUI to make creating different autocomplete engines easier as well as making queries easier as well. Hopefully you find it easier to work with as well! You will see the following appear after running ./main

**0: Choose corpus and run engine

**1: Leave

Input 0 to choose the corpus.

You will then be prompted to enter the corpus file name. I have already created two corpora. 

small_corpus.txt holds the example file given in write up ( bat,Bat,bar,bark)

medium_corpus.txt holds 2500 words

If you want to put in your own corpus, please place a corpus inside the same folder as the program.

After inputting 0 you will be prompted will the following line:

**Enter the textfile name. Example corpus_name.txt**

Input your corpus file. Example: small_corpus.txt

You then  see the following appear:

Hello! Welcome to Stateless Autocomplete Engine!
Please enter query in the exact form complete,prefix,return_amount
Example: complete,ba,1

**Enter the query exactly in the form of complete,prefix,num_returns. No spaces!**

It will then output the autocomplete results with the first results values being sorted by how frequent they are. **Note the query complete,,0 will output nothing rather than everything because google autocomplete doesn't give any results until there is at least 1 letter**

You can then decided to enter another query by inputting yes or no. 

If you choose no, you will then be prompted back to the main menu where you can go back and use a different corpus or leave.
