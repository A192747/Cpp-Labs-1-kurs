#ifndef QUEUEFLOW_H
#define QUEUEFLOW_H
#include <iostream>
#include "Queue.h"
#include <exception>


struct QueueOverflow : std::exception
{
	const char* what() const noexcept { return "\nError: queue overflow!\n"; }
};


struct QueueUnderflow : std::exception
{
	const char* what() const noexcept { return "\nError: queue underflow!\n"; }
};


struct WrongQueueSize : std::exception
{
	const char* what() const noexcept { return "\nError: wrong queue size!\n"; }
};


#endif