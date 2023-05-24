```markdown
# Concurrent Programming with C++ Futures

This is a simple C++ program that demonstrates the use of the `<future>` library to create asynchronous tasks, which is an example of concurrent programming.

## Code Breakdown

1. The program first prints the ID of the main thread:

   ```cpp
   std::cout << "Main thread id: " << std::this_thread::get_id() << std::endl;
   ```

2. An empty vector of `std::future<void>` objects is created. A `std::future` represents a potentially asynchronous computation:

   ```cpp
   std::vector<std::future<void>> futures;
   ```

3. The program then enters a loop where it does the following for 20 times:

   - An asynchronous task is launched with `std::async`. The task can either be executed lazily when the result is requested (deferred), or it can be executed in a separate, new thread (asynchronous):

     ```cpp
     auto fut = std::async(std::launch::deferred|std::launch::async,[]
     {
       std::this_thread::sleep_for(std::chrono::seconds(1));
       std::cout << std::this_thread::get_id() << " "<< std::endl;
     });
     ```

   - The returned `std::future` from the `std::async` call is moved into the vector of futures:

     ```cpp
     futures.push_back(std::move(fut));
     ```

4. After launching all the tasks, the program waits for all of them to complete, ensuring that all tasks are finished before the program continues:

   ```cpp
   std::for_each(futures.begin(), futures.end(), [](std::future<void> & fut)
   {
     fut.wait();
   });
   ```

5. Finally, the program prints a newline:

   ```cpp
   std::cout << std::endl;
   ```

## Expected Output

When running this program, you will see it printing the ID of the main thread, and then the IDs of 20 other threads. However, note that because of the `std::launch::deferred|std::launch::async` policy, it's not guaranteed that each task will be run in a separate thread. This depends on the specific implementation of the C++ standard library.
```

Note: To properly render this as a README.md file, simply copy the content and save it to a file named `README.md` in the root of your project directory. This file will automatically be displayed on your project's home page if you're using a version control system like Git and hosting your project on a site like GitHub.
