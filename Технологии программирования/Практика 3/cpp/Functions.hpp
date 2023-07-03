#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Point.hpp"
#include "Check.hpp"
#include <string>
#include <iostream>
#include <exception> 
#include <iomanip> 

size_t getCategory(const std::string& str);

void vertexes(size_t category, const std::vector<Polygon>& vector);

void area(size_t category, const std::vector<Polygon>& vector);

void rects(const std::vector<Polygon>& vector);

void same(const std::vector<Polygon>& vector);

void coutResult(std::istream& in, const std::vector<Polygon>& vector);


#endif
