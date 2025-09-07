#include <thread>
#include <iostream>
#include "threads.hpp"

using std::thread;

/*****************************************************
*@brief make_thread_single
*@param function 
*@retval void
******************************************************/
void Threads::make_thread_single(void(*ptrfunc)())
{
	thread thread(ptrfunc);
	thread.join();
}

/*****************************************************
*@brief make_thread_single
*@param x,y receives to numbers that will be added in the function.
*@retval void
******************************************************/
void Threads::make_thread_single(void(*ptrfunc)(int,int),int x,int y)
{
	thread thread(ptrfunc,x,y);
	thread.join();
}

/*****************************************************
*@brief make_threads
*@param functions receives a vector of void function pointers that receives and returns no parameters.
*@retval thread status from @enum ThreadStatus
******************************************************/
Threads::ThreadStatus Threads::make_threads(std::vector<void(*)()> functions)
{
	const unsigned int size = functions.size();
	Threads::ThreadStatus status;

	status = size < std::numeric_limits<unsigned int>::max() ? 
				(size > 0 ? Threads::ThreadStatus::SUCCESS : Threads::ThreadStatus::MIN_SIZE_ERROR):
				Threads::ThreadStatus::MAX_SIZE_ERROR;

	if(status == Threads::ThreadStatus::SUCCESS)
	{
		for( unsigned int index = 0;index < size ;index++)
		{
			make_thread_single(functions.at(index));
		}
	}
	return status;
}

