#include <thread>
#include <iostream>
#include "threads.hpp"

using std::thread;

/*****************************************************
*@name make_thread_single
*@param function 
*@return void
******************************************************/
void Threads::make_thread_single(void(*ptrfunc)())
{
	thread thread(ptrfunc);
	thread.join();
}

/*****************************************************
*@name make_threads
*@param functions
*@return void
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
