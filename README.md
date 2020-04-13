# Spell Checker

## How to run?
To run my program, you need an english.txt file. If you have this file,
you can do the following command <code>make</code> this will create an executable which can be ran by doing <code>./run</code>
Without the english.txt file in the directory where this program is located, this program will not work. It needs to contain one word on each line, can be capitalized or non capitalized. The file must be named "english.txt" for this program to work

## What does it do?
This program is a Spell Check program that takes a dictionary or "english.txt" file, full of words and inserts them into a Hash Table to be used as a reference for words used in a sentence or paragraph. Then, the program will prompt you to enter a word, phrase, sentence, or paragraph you would like to have spell checked. My program will return the misspelled words and return a list of suggestions as to what this word could be replaced with based on the words from the dictionary in my Hash Table.

## Bonus Completed
Colored outputs included ✔
Multiple hash functions 𝙭
Accept each suggestion 𝙭

## Important Files 
english.txt - text file of words that form the dictionary
run - executable to run the program, does not take a second command line argument, have english.txt in the same directory to work properly

## English.txt File Format
Example:

Start of File
word1
word2
word3
word4
word5
End of File

Words must be on a different line with no variation in spacing. No left or right spacing.
Words can be capitalized and punctuated in the english.txt as my program eliminates those 
aspects upon execution.

## Hash Choice
My decision to use multiplication hashing to turn strings into size_t's was based off
my previous success on the hashing lab where I also used multiplication hashing.
I find multiplication hashing easier and more forgiving as I am used to the structure of it.
It is easy to adjust values as needed to fit your Hash Table needs and hit the amount of buckets
you wish to be filled.

## Approach to String Parsing Problem
I researched string parsing and C++ and how to turn capitalized characters into lower case
and found how to do that, implementing it into my project. Also, I found ideas on how to spell check by adding, deleting, replacing, and swapping characters in order to find new words.
Overall, string parsing in C++ is sub-par compared to other languages like JavaScript xD.

## Other Difficulties
At first, I found the hashing function very daunting. However, after reviewing my lab code and making a few alterations, I made it work for this project. I had to tweak a few numbers in order to get the desired number of buckets filled (80% as specified by the guidelines). By tweaking this function I was able to get 94% filled, I could have made this 100% if I were to shrink my default constructors array to 9400 elements instead of 10000, but I want to leave room for error when considering users adding their own words to the file.
