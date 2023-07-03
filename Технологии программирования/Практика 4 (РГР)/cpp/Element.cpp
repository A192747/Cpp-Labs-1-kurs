#include "Element.hpp"
#include <iostream>
#include <string>

static size_t global_number = 0;

std::istream& operator >> (std::istream& in, Element& data)
{
	data.words.clear();
	std::string str = "";
	std::string str0 = "";
	std::getline(in, str);
	global_number++;
	if (!str.size())
	{
		std::getline(in, str);
	}
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] != ' ' and i != str.size() - 1)
			str0 += str[i];
		else
		{

			if (i == str.size() - 1)
				str0 += str[i];
			if (str0.size() != 0)
			{
				data.line = global_number;
				data.words.push_back(str0);
			}
			str0 = "";
		}
	}
	return in;
}

std::ostream& operator << (std::ostream& out, const Element& data)
{
	out << data.line << ". ";
	for (auto it = data.words.begin(); it != data.words.end(); ++it)
	{
		out << it->c_str() << " ";
	}
	return out;
}
