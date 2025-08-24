# Concurrency

    Doing things at the same time. For example:
    Computer that is running many programs at the same time.

# Launching a thread.

    processor(cpu)
        |
        |
      ------------------
      |                |
    core_0..........core_n-1
      |               |
    thread0,1,.(n-1)..thread0,1,....n-1
    

	std::thread thread(thread_hello); // Creates a new thread that runs the thread_hello function.
    thread.join(); // Waits for the thread to finish, preventing std::terminate if the main thread ends first.
