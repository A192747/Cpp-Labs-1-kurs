#ifndef MYEXEPTION_H
#define MYEXEPTION_H

#include <exception>

struct Wrong_Side_Size : public std::exception 
{
	const char* what() const throw () 
	{
		return "Error side size!\n";
	}
};
#endif
