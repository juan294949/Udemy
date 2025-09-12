# System thread interface.
  Some functionalities are not available in standart C++
    -Can not adjust the priority of the thread.
    -Can not assign affinity to an specific thread.
  
# Native handle.
  Get the handle associated with an thread object.
  -MyThread.native_handle();

# Thread ID.
  ## Return the identifier ID for the main thread.
  std::this_thread::get_id();

  ## Return the identifier ID for the child process.
  MyThread.get_id();

# Pausing threads.
  ## Using C++14.
    std::this_thread::sleep_for(2s)
  ## Using C++11.
    std::this_thread::sleep_for(std::chrono::seconds(2));

# 