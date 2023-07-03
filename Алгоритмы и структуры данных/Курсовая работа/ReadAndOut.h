#ifndef READANDOUT_H
#define READANDOUT_H
#include <iostream>
#include <string>
#include "BinarySearchTree.h"


void readWrite(std::istream& input, std::ostream& output, BinarySearchTree & Tree)
{
	int strCount = 0;
	std::string str = "";
	std::string str0 = "";
	while (!input.eof())
	{
		
		std::getline(input, str);
		if (str.size())
		{
			strCount++;
			output << strCount << ". " << str << "\n";
		}
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != ' ' and i != str.size() - 1)
				str0 += str[i];
			else
			{
				
				if (i == str.size() - 1)
					str0 += str[i];
				if(str0 != "")
					Tree.insert(str0, strCount);
				str0 = "";
			}
		}
	}
}

#endif