#include "Rhombus.h"
#include "MyExeption.h"

Rhombus::Rhombus(unsigned int&& size)
{
	if (size >= 100)
	{
		throw Wrong_Side_Size();
	}
	else
	{
		side_ = size;
	}
}

Rhombus::Rhombus(const Rhombus& other)
{
	side_ = other.side_;
}

void Rhombus::side(unsigned int&& size)
{
	if (size >= 100)
	{
		throw Wrong_Side_Size();
	}
	else
	{
		side_ = size;
	}
}

