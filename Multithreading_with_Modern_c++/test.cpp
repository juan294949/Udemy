#include <iostream>
#include "section3_Introduction_to_concurrency/threads.hpp"
#include <utility>
#include <limits>

void test_thread(void);
void assignament1(void);
void assignament_Thread_function_with_arguments(int x,int y);
void add_two_numbers(int x,int y);
void menu(void);

int main()
{
	menu();
	return 0;
}

void menu(void)
{
	bool shutdown = false;
	unsigned short assignament =0;
	std::vector<void(*)()> function;
	Threads mythread;

	while(!shutdown)
	{
		std::cout << "\nFrom the following choices pick one\n\
									\r 1). Assignament 1\n\
									\r 2). Test the make_threads function\n\
									\r 3). assignament_Thread_function_with_arguments \n\
									\r Anything else Quits the program\n";

		std::cin >> assignament;
		switch (assignament)
		{
			case 1:
				//Now modify your program so that it plays the game in a separate thread.
				function.push_back(assignament1);
				mythread.make_threads(function);

			break;

			case 2:
				
				test_thread();

			break;

			case 3:

				assignament_Thread_function_with_arguments(5,20);

			break;

			default:
		
				std::cout << "invalid input leaving now...\n";
				shutdown = true;

			break;
		}
	}
}
// testing thread function.
void test_thread(void)
{

	auto function1 = [](void){std::cout << "thread 1 running\n";};
	auto function2 = [](void){std::cout << "thread 2 running\n";};

	Threads mythread;
	
	std::vector<void(*) ()>my_functions;

	void (*ptr_function1)() = function1; // pointer to function1 address.
	void (*ptr_function2)() = function2; // pointer to function2 address.

	my_functions.push_back(function1);
	my_functions.push_back(function2);

	mythread.make_threads(my_functions);

}

/*****************************************************
*@brief assignament1
*			if the number is divisible by 3, they say "fizz" instead of the number. If the number is divisible by 5, they say "buzz"
*			if the number is divisible by 3 and by 5, they say "fizzbuzz"
*
*@param function 
*@retval void
******************************************************/
void assignament1(void)
{
	std::string names[] = {"Abdul","Bart","Claudia","Divya"};
	char val1 =0;
	bool val2 =0;
	std::string* ptrNames = names;
	std::string* ptrNames_start = names;
	std::string* ptrNames_end = ptrNames_start + sizeof(names)/sizeof(*names);
	
	unsigned char limit = std::numeric_limits<unsigned char>::max();

	for(unsigned short number = 1; number <= limit ; number++ )
	{
		val1 = number%3 == 0 ? 1 : 0;
		val2 = number%5 == 0 ? 1 : 0;
		if( val1 && val2){std::cout << *ptrNames << " says Fizzbuzz\n";number++;}
		else if(val1){std::cout << *ptrNames << " says Fizz\n";number++;}
		else if(val2){std::cout << *ptrNames << " says Buzz\n";number++;}
		std::cout << *ptrNames << " says "<<number<<"\n";
		ptrNames++;
		if(ptrNames >= ptrNames_end){ptrNames = ptrNames_start;}
	}
}

/*****************************************************
*@brief assignament-Thread-function-with-arguments
*			Write a program with a thread that receives two ints, prints their
*			values and displays their sum.
*@param function 
*@retval void
******************************************************/
void assignament_Thread_function_with_arguments(int x,int y)
{
	auto lamda = [](int x,int y)
	{
		std::cout << "The sum of " << x << " + "<<y<<" is = " <<"\033[1;32m"<<(x+y)<< "\033[0m"<<"\n";
	};

	Threads mythread;
	std::cout << "\n\rUsing A regular function \n";
	mythread.make_thread_single(add_two_numbers,x,y);
	std::cout << "\n\rUsing A functor TODO: Not available! \n";

	std::cout << "\n\rUsing lamda\n";
	mythread.make_thread_single(lamda,x,y);

}

/*****************************************************
*@brief add_two_numbers.
*@param x,y two numbers to add.
*@retval void
******************************************************/
void add_two_numbers(int x,int y)
{
	std::cout << "The sum of " << x << " + "<<y<<" is = " <<"\033[1;32m"<<(x+y)<< "\033[0m"<<"\n";
}
