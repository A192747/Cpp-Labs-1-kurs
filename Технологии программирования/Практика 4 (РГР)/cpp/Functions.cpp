#include "Functions.hpp"
#include "Element.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>  

static size_t maxWordSize = 0;

bool find(std::string str, std::vector< Table_element>& table)
{
	for (auto it = table.begin(); it != table.end(); ++it)
	{
		if (it->word == str)
			return 1;
	}
	return 0;
}

bool comparator(const Table_element& lhs, const Table_element& rhs)
{
	if (lhs.word != rhs.word)
	{
		return lhs.word < rhs.word;
	}
}

void coutResult(std::istream& in, const std::vector<Element>& vector, std::ostream& out)
{
	std::string str;
	std::getline(in, str);
	if (str == "GET LINES")
	{
		std::copy(vector.begin(), vector.end(), std::ostream_iterator <Element>(out, "\n"));
	}
	else
	{
		if (str == "GET TABLE")
		{
			std::vector< Table_element> table;
			
			for (auto it = vector.begin(); it != vector.end(); ++it)
			{
				for (auto elem = it->words.begin(); elem != it->words.end(); ++elem)
				{
					if (!find(elem->c_str(), table))
					{
						/*table_element.lines.clear();*/
						Table_element table_element;
						table_element.lines.push_back(it->line);
						table_element.word = elem->c_str();
						maxWordSize = std::max(maxWordSize, table_element.word.size());
						table.push_back(table_element);
						
					}
					else
					{
						for (auto its = table.begin(); its != table.end(); ++its)
						{
							if (its->word == elem->c_str())
							{
								its->lines.push_back(it->line);
								break;
							}
						}
					}
				}
			}
			std::sort(table.begin(), table.end(), comparator);
			getTable(out, table);
		}
		else
		{
			if(str == "INFO")
				outInfo(out);
			else
				throw std::logic_error("<INVALID COMMAND>\n");
		}
	}
}

void outInfo(std::ostream& out)
{
	out << "Write: 'GET LINES' - to get rows with their numbers\n"
		<< "Write: 'GET TABLE' - to get a sorted table with row numbers where words occur\n"
		<< "Write: 'INFO' - to get info about available commands\n";
}

void getTable(std::ostream& out, const std::vector<Table_element>& vector)
{
	for (size_t i = 0; i < maxWordSize * 2; i++)
		out << "-";
	out << "\n";
	out << std::setw(maxWordSize + 1) << std::left << "| Words" << "  |" << "On which line " << "\n";
	for (size_t i = 0; i < maxWordSize * 2; i++)
		out << "-";
	out << "\n";
	for (auto its = vector.begin(); its != vector.end(); ++its)
	{
		out << "| " << std::setw(maxWordSize + 1) << std::left << its->word << "| ";
		std::copy(its->lines.begin(), its->lines.end(), std::ostream_iterator <size_t>(out, " "));
		out << "\n";
	}
	for (size_t i = 0; i < maxWordSize * 2; i++)
		out << "-";
	out << "\n";
}
