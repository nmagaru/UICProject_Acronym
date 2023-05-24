// Main implementations for char manipulation

#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

class characterParser
{
private:
    char* array;
    int length;

public:
    // Default constructor
    //
    // Constructs an empty string
    characterParser();

    // Parametrized constructor
    //
    //  Builds a characterParser deep copied from a char *
    characterParser(char* str);

    // Parametrized constructor
    //
    //  Builds a characterParser deep copied from a std::string
    characterParser(std::string str);

   
    // This iterator has been provided for you
    // and iterates over every character in the container
    class charIterator;

    class acronymIterator;


    // begin()
    //
    //  Returns an charIterator pointing to the first element of the string.
    charIterator charbegin();
    //  Returns an acronymIterator pointing to the first element of the string.
    acronymIterator begin();

    // end()
    //
    //  Returns an charIterator pointing "after" the last element of the string.
    charIterator charend();
    //  Returns an acronymIterator pointing "after" the last element of the string.
    acronymIterator end();

    // printAllCharacters()
    //
    //  Sends all the characters in the CharacterParser container to standard input in order
    //  Adds a new line at the end of the output
    void printAllCharacters();

};