# Concurrency.

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

# Passing functions with arguments to threads.

    thread MyThread(function,std::ref(MyString)...........ect);
    
# Single Processor and Cache.

  ## Level 1 Cache.
    - Provate to each processor core.
    - As close to the core as possible.
  ## Level 2 Cache.
    - Usually private to each core.
  ## Level 3 Cache.
    - Shared by all cores on the same socket.

  core1|L1_Cache <-------> L2_Cache \
                                     \
                                      \
                                       |-> L3_Cache.
                                      /
                                     /
  core2|L1_Cache <-------> L2_Cache /
  