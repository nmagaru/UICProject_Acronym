// Main implementations for char manipulation

#include "characterParser.h"
#include "charIterator.h"
#include "acronymIterator.h"

#pragma warning(disable : 4996)

// Default constructor
//
// Constructs an empty string
characterParser::characterParser()
    : array(nullptr), length(0)
{    }

// Parametrized constructor
//
//  Builds a characterParser deep copied from a char *
characterParser::characterParser(char* str)
{
    int len = std::strlen(str);
    array = new char[len + 1];
    std::strncpy(array, str, len);
    // If on windows:     
    //strncpy_s(array, len + 1, str, len);
    array[len] = '\0';
    length = len;
}

// Parametrized constructor
//
//  Builds a characterParser deep copied from a std::string
characterParser::characterParser(std::string str)
{
    int len = str.length();
    array = new char[len + 1];
    std::strncpy(array, str.c_str(), len);
    // If on windows:    
    //strncpy_s(array, len + 1, str.c_str(), len);
    array[len] = '\0';
    length = len;
}

// charIterator begin()
//
//  Returns an charIterator pointing to the first element of the string.
characterParser::charIterator characterParser::charbegin()
{
    return charIterator(array);
}

// charIterator end()
//
//  Returns an charIterator pointing "after" the last element of the string.
characterParser::charIterator characterParser::charend()
{
    return charIterator(array + length);
}

// acronymIterator begin()
//
//  Returns an acronymIterator pointing to the first element of the string.
characterParser::acronymIterator characterParser::begin()
{
    int counter = 0;

    for (auto iter = this->charbegin(); iter != this->charend(); ++iter)
    {
        if (!isalpha(*iter))
            ++counter;
        else
            break;
    }

    return acronymIterator(array + counter);
}

// acronymIterator end()
//
//  Returns an acronymIterator pointing "after" the last element of the string.
characterParser::acronymIterator characterParser::end()
{
    return acronymIterator(array + length);
}

// printAllCharacters
//
// Prints every character in the characterParser
// Requires modification after the default iterator has been changed
void characterParser::printAllCharacters()
{
    for (auto iter = this->charbegin(); iter != this->charend(); ++iter)
    {
        std::cout << *iter;
    }
    std::cout << std::endl;
}


