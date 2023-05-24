// Function definitions for the acronymIterator class

#pragma once
#include "characterParser.h" 
#include <iterator>

using namespace std;

class characterParser::acronymIterator
{
public:
	using iterator_category = std::forward_iterator_tag;
	using value_type = char*;
	using difference_type = std::ptrdiff_t;
	using pointer = char*;
	using reference = char&;

private:
	char* curr;

public:

	acronymIterator(char* arr);

	char& operator*();

	acronymIterator& operator++();

	bool operator!=(const acronymIterator& other);

	bool operator==(const acronymIterator& other);

};


