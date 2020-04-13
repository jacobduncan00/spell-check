#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>

// Color codes used in .cpp

#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BOLDBLACK "\033[1m\033[30m"
#define BOLDRED "\033[1m\033[31m"
#define BOLDGREEN "\033[1m\033[32m"
#define BOLDYELLOW "\033[1m\033[33m"
#define BOLDBLUE "\033[1m\033[34m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDCYAN "\033[1m\033[36m"
#define BOLDWHITE "\033[1m\033[37m"

// Actual HashTable
class HashTable
{

private:
  // Linked list aspect of HashTable
  struct HashNode
  {
    // Each node contains a word, next, and previous
    std::string word;
    HashNode *next;
    HashNode *prev;
  };

  HashNode *head;
  HashNode *tail;

public:
  // Default constructor
  HashTable();
  // Copy constructor
  HashTable(const HashTable &);
  // Destructor
  ~HashTable();
  // Overloaded Assignment Operator
  HashTable &operator=(const HashTable &);
  // Function to generate a new node to be inserted into the HashTable
  HashNode *genNode(std::string);
  // Function that inserts a word into the HashTable
  void insertWord(std::string);
  // Function that prints the nodes of HashTable
  void print();
  // Function that determines whether a word is in the HashTable or not
  bool inTable(std::string);
  // Function that returns the length of the HashTable
  int getLen();
  // Function that returns the linked list of strings
  std::string *getWords();
  // Function to clear the HashTable of all nodes
  void clear();
};

#endif
