#ifndef STRACKFLOW_H
#define STRACKFLOW_H
#include <iostream>
#include "Stack.h"
#include <exception>


struct StackOverflow : std::exception
{
	const char* what() const noexcept { return "Error: stack overflow!\n"; }
};


struct StackUnderflow : std::exception
{
	const char* what() const noexcept { return "Error: stack underflow!\n"; }
};


struct WrongStackSize : std::exception
{
	const char* what() const noexcept { return "Error: wrong stack size!\n"; }
};

#endif