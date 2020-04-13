#include "Dictionary.h"

// Default Constructor
// Creates an array "Dictionary" size of 10000
// and assigns each index of the used array to zero

Dictionary::Dictionary()
{
  arr = new HashTable[10000];
  tableSize = 10000;
  used = new int[tableSize];
  // Set all used to 0 so they are not counted as used buckets
  for (int i = 0; i < tableSize; i++)
  {
    used[i] = 0;
  }
}

// Copy Constructor that copies the contents of one Dictionary to another

Dictionary::Dictionary(const Dictionary &param)
{
  arr = new HashTable[param.tableSize];
  tableSize = param.tableSize;
  used = new int[param.tableSize];
  for (int i = 0; i < tableSize; i++)
  {
    arr[i] = param.arr[i];
  }
  for (int i = 0; i < tableSize; i++)
  {
    used[i] = param.used[i];
  }
}

// Destructor, deletes the arr array and used array

Dictionary::~Dictionary()
{
  delete[] arr;
  delete[] used;
}

// Overloaded operator function that assisgns one Dictionary to another

Dictionary &Dictionary::operator=(const Dictionary &rhs)
{
  // Need to go through each HashTable node and their
  // HashNode and copy to new HashTable with new HashNodes
  if (this == &rhs)
  {
    return *this;
  }
  // destructing previous
  delete[] arr;
  delete[] used;
  // creating new
  arr = new HashTable[rhs.tableSize];
  tableSize = rhs.tableSize;
  used = new int[rhs.tableSize];
  for (int i = 0; i < tableSize; i++)
  {
    arr[i] = rhs.arr[i];
  }
  for (int i = 0; i < tableSize; i++)
  {
    used[i] = rhs.used[i];
  }
  return *this;
}

// Function that uses multiplicative hashing to turn a string into a
// size_t which can then be put into the HashTable as an index

size_t Dictionary::multHash(std::string str)
{
  size_t w = pow(2, 32);
  size_t p = 19;
  size_t a = 2971215073;
  size_t sum = 0;
  for (size_t i = 0; i < str.length(); i++)
  {
    sum += ((size_t)(str[i])) * (i * 5);
  }
  size_t rtn = floor(((a * sum) % w) / pow(2, 32 - p));
  return rtn % tableSize;
}

// Function that inserts a bucket into the HashTable using multHash

void Dictionary::insertBucket(std::string str)
{
  arr[multHash(str)].insertWord(str);
  used[multHash(str)]++;
}

// Function that prints the HashTable nodes

void Dictionary::print()
{
  for (int i = 0; i < 10; i++)
  {
    // Calls print from HashTable.cpp to print the LL of strings
    arr[i].print();
  }
}

// Function that iterates through the used Dictionary nodes
// and finds the one with the smallest used arr

int Dictionary::smallestBucket()
{
  int min = 10000;
  for (int i = 0; i < tableSize; i++)
  {
    if (used[i] < min && used[i] > 0)
    {
      min = used[i];
    }
  }
  return min;
}

// Function that iterates through used Dictionary nodes
// and finds the one with the largest used arr

int Dictionary::largestBucket()
{
  int max = 0;
  for (int i = 0; i < tableSize; i++)
  {
    if (used[i] > max)
    {
      max = used[i];
    }
  }
  return max;
}

// Function that iterates through used Dictionary nodes
// and counts which nodes hold more than 0 elements

int Dictionary::usedBuckets()
{
  int count = 0;
  for (int i = 0; i < tableSize; i++)
  {
    if (used[i] > 0)
    {
      count++;
    }
  }
  return count;
}

// Function that returns the HashTable size

int Dictionary::getTableSize()
{
  return tableSize;
}

// Function that returns the number of average buckets used in the HashTable

int Dictionary::averageBucket()
{
  int sum = 0;
  for (int i = 0; i < tableSize; i++)
  {
    sum += used[i];
  }
  double rtn = sum / tableSize;
  return (int)rtn;
}

// Function that checks whether a specfici word is in the HashTable
// or not and returns a boolean

bool Dictionary::inHash(std::string str)
{
  bool rtn = arr[multHash(str)].inTable(str);
  return rtn;
}

// Function that takes in a word and creates a HashTable of suggestions for
// the word passed in by checking replace, add, del, and swap suggestions
// Function returns a HashTable of suggestions
// Don't know if it matters what order the suggestions are in

HashTable Dictionary::suggest(std::string str)
{
  HashTable suggestions;
  swap(suggestions, str);
  replace(suggestions, str);
  del(suggestions, str);
  add(suggestions, str);
  return suggestions;
}

// Function that suggests two edit distance words from the previous HashTable of
// suggestions. This function returns an integer to the main to be added with the
// suggestionCounter to display total number of suggestions the program generates.

int Dictionary::suggest(HashTable ext)
{
  std::string *oneEditWords = ext.getWords();
  int arr[50];
  for (int i = 0; i < ext.getLen(); i++)
  {
    HashTable moreSuggestions;
    std::cout << "Suggestions for " << BOLDRED << oneEditWords[i] << RESET << ": ";
    swap(moreSuggestions, oneEditWords[i]);
    replace(moreSuggestions, oneEditWords[i]);
    del(moreSuggestions, oneEditWords[i]);
    add(moreSuggestions, oneEditWords[i]);
    arr[i] = moreSuggestions.getLen();
    moreSuggestions.print();
    moreSuggestions.clear();
    std::cout << std::endl;
    if (i == ext.getLen() - 1)
    {
      int sum = 0;
      for (int i = 0; i < ext.getLen(); i++)
      {
        // Gets number of extended suggestions
        sum += arr[i];
      }
      delete[] oneEditWords;
      // returns that number to main to be added with original suggestion counter
      return sum;
    }
  }
  // If something went wrong
  // std::cout << "No Suggestions" << std::endl;
  // std::cout << "Returning 0" << std::endl;
  return 0;
}

// Function that loops through alphabet and attempts to add letters in different
// locations of the word in order to form a suggestion

void Dictionary::add(HashTable &suggestions, std::string str)
{
  std::string holdWord = str;
  for (int i = 0; i < holdWord.length(); i++)
  {
    for (char j = 'a'; j <= 'z'; j++)
    {
      str = str.substr(0, i) + j + str.substr(i, holdWord.length());
      if (inHash(str) && str != holdWord)
      {
        suggestions.insertWord(str);
      }
      // reset back to original
      str = holdWord;
    }
  }
}

// Function that attempts to generate suggestion words by deleting
// characters from different positions in the word

void Dictionary::del(HashTable &suggestions, std::string str)
{
  std::string holdWord = str;
  for (int i = 0; i < holdWord.length(); i++)
  {
    // removes character at each i index
    str.erase(i, 1);
    // If word with character deleted is in HashTable and not the same
    if (inHash(str) && str != holdWord)
    {
      // Insert that word into the HashTable
      suggestions.insertWord(str);
    }
    // reset back to original
    str = holdWord;
  }
}

// Function that attempts to generate suggestion words by swapping characters
// from different positions in the word

void Dictionary::swap(HashTable &suggestions, std::string str)
{
  std::string holdWord = str;
  for (int i = 0; i < holdWord.length(); i++)
  {
    for (int j = i + 1; j < holdWord.length(); j++)
    {
      // if not at the same index
      if (i != j)
      {
        // swap characters
        std::swap(str[i], str[j]);
        if (inHash(str) && str != holdWord)
        {
          suggestions.insertWord(str);
        }
        // reset back to original
        str = holdWord;
      }
    }
  }
}

// Function that attempts to generate suggestion words by replacing certain
// characters in the word with different characters

void Dictionary::replace(HashTable &suggestions, std::string str)
{
  std::string holdWord = str;
  for (int i = 0; i < holdWord.length(); i++)
  {
    for (char j = 'a'; j <= 'z'; j++)
    {
      // replace with what current character j incrementor is on
      str[i] = j;
      if (inHash(str) && str != holdWord)
      {
        suggestions.insertWord(str);
      }
      // reset back to original
      str = holdWord;
    }
  }
}
