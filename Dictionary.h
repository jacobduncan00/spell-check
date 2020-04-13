#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <string.h>
#include <iomanip>
#include <math.h>
#include "HashTable.h"

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

class Dictionary
{

private:
  HashTable *arr;
  // # of total buckets
  int tableSize;
  // array to keep track of used buckets
  int *used;

public:
  // Default Constructor
  Dictionary();
  // Copy Constructor
  Dictionary(const Dictionary &);
  // Destructor
  ~Dictionary();
  // Overloaded Assignment Operator
  Dictionary &operator=(const Dictionary &);
  // Multiplicative string hashing
  size_t multHash(std::string);
  // Prints HashTable
  void print();
  // Insert bucket into HashTable
  void insertBucket(std::string);
  // Returns bucket with smallest size
  int smallestBucket();
  // Returns bucket with largest size
  int largestBucket();
  // Returns number of used buckets
  int usedBuckets();
  // Returns HashTable size (10000)
  int getTableSize();
  // Returns the average of bucket sizes
  int averageBucket();
  // Function that determines whether a certain word is in the HashTable or not
  bool inHash(std::string);
  // One-edit distance suggestion function
  HashTable suggest(std::string);
  // Two-edit distance suggestion function
  int suggest(HashTable);
  // Suggestion by adding characters to string
  void add(HashTable &, std::string);
  // Suggestion by deleting characters in string
  void del(HashTable &, std::string);
  // Suggestion by swapping characters in string
  void swap(HashTable &, std::string);
  // Suggestion by replacing characters in string
  void replace(HashTable &, std::string);
};

#endif
