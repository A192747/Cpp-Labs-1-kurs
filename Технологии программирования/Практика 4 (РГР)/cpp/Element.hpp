#ifndef ELEMENT_H
#define ELEMENT_H

#include <vector>
#include <iostream>

struct Element
{
public:
	size_t line;
	std::vector<std::string> words;
};

struct Table_element
{
public:
	std::string word;
	std::vector<size_t> lines;
};

std::istream& operator >> (std::istream& in, Element& data);
std::ostream& operator << (std::ostream& out, const Element& data);

#endif
