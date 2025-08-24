#include <vector>

class Threads
{
	enum ThreadStatus
	{
		SUCCESS = 0,
		FAILURE = 1,
		MAX_SIZE_ERROR = 2,
		MIN_SIZE_ERROR = 3
	};

	private:

		void make_thread_single(void(*ptrfunc)());

	public:

		Threads(){}

		// Member functions (methods) section.
		ThreadStatus make_threads(std::vector<void(*)()> functions);

		// Data Members section.
};