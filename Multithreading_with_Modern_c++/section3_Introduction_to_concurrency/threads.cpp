#include <thread>
#include <iostream>

void thread_hello(){

	std::cout << "Hello from child thread 1 " << "\n";

}

int main(void){

	std::thread thread(thread_hello);
	thread.join();
	return 0;
}