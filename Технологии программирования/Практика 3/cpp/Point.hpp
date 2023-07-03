#ifndef POINT_HPP
#define POINT_HPP

#include <vector>
#include <iostream>

struct Point
{
	int x, y;
};

struct Polygon
{
	std::vector< Point > points;
};

std::istream& operator >> (std::istream& in, Polygon& data);
std::ostream& operator << (std::ostream& out, const Polygon& data);

#endif
