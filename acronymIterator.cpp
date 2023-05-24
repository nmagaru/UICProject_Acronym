// Function definitions for the acronymIterator class

#include "acronymIterator.h"

using namespace std;

characterParser::acronymIterator::acronymIterator(char* arr)
{
    curr = arr;
}

char& characterParser::acronymIterator::operator*()
{
    *curr = toupper(*curr);
    return *curr;
}

characterParser::acronymIterator& characterParser::acronymIterator::operator++()
{

    while (*curr != '\0')
    {
        if (*curr == ' ' || *curr == '\"' || *curr == '(')
        {
            ++curr;

            while (*curr == ' ' || *curr == '\"' || *curr == '(')
                ++curr;

            if (isalpha(*curr))
                break;
            else
                continue;
        }
        else 
        {
            ++curr;
        } 
    }
       
    return *this;
}

bool characterParser::acronymIterator::operator!=(const characterParser::acronymIterator& other)
{
    return curr != other.curr;
}

bool characterParser::acronymIterator::operator==(const characterParser::acronymIterator& other)
{
    return curr == other.curr;
}

