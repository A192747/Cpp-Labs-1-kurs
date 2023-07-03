#ifndef DATASTRUCT_H
#define DATASTRUCT_H

#include <string>
#include <utility> //для std::pair
#include <iostream>


struct DataStruct
{
	long long key1;
	std::pair< long long, unsigned long long > key2;
	std::string key3;
	std::string acronym;
};

std::istream& operator >> (std::istream& in, DataStruct& data);
std::ostream& operator << (std::ostream& out, const DataStruct& data);
bool comparator(const DataStruct& lhs, const DataStruct& rhs);

#endif
