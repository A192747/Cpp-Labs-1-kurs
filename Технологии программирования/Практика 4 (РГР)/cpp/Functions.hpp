#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>
#include "Element.hpp"

void coutResult(std::istream& in, const std::vector<Element>& vector, std::ostream& out);

void outInfo(std::ostream& out);

void getTable(std::ostream& out, const std::vector<Table_element>& vector);

bool comparator(const Table_element& lhs, const Table_element& rhs);

#endif
