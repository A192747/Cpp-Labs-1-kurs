#include "Square.h"
#include "MyExeption.h"


void Square::side(unsigned int&& size)
{
	if (size >= 100)
	{
		side_ = 1;
		throw Wrong_Side_Size();
	}
	else
	{
		side_ = size;
	}
}
