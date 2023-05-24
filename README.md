# Concurrent Programming with C++ Futures : Milewski Example

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

# Concurrent Programming with C++ Futures : concurrency_presentation.cpp examples
This C++ program illustrates several aspects of concurrent programming using C++ <future> and <async>. The program executes different tasks depending on the command line argument provided when launching it.

Here is a breakdown of the program:

Function called_from_async(): This function simply outputs a message saying "Async call". It is intended to be called asynchronously.

Function twice(int m): This function simply doubles the input integer and returns it.

Function parallel_sum(RandomIt beg, RandomIt end): This function calculates the sum of a range of elements using a divide-and-conquer approach. If the range is less than 1000, it directly calculates the sum using std::accumulate(). Otherwise, it divides the range into two halves, processes the first half directly, and launches a new task to process the second half. It then waits for the result of the second task and returns the total sum. This approach allows it to potentially calculate the sum in parallel, depending on how many threads are available.

The main() function accepts a command-line argument, and based on its value, it executes one of the four tests.

Readme markdown:
markdown
Copy code
# Concurrency with C++ Futures and Async

This project showcases various usages of the `<future>` and `<async>` library for concurrent programming in C++.

## Main Components

1. **Test 1:** Launches an asynchronous task that executes the `called_from_async()` function and outputs "Async call". The main thread waits for this task to finish before proceeding.

2. **Test 2:** Launches an asynchronous task that adds two numbers (2 and 4) together using a lambda function. The result is retrieved and printed.

3. **Test 3:** Creates a vector of futures, each of which will hold the result of an asynchronous task that doubles a number from 0 to 9. All tasks are launched, and their results are retrieved and printed.

4. **Test 4:** Demonstrates how to calculate the sum of a large range of numbers in parallel using a divide-and-conquer approach.

## Running the Code

Compile and run the code providing a command-line argument (1, 2, 3, or 4) to choose the corresponding test.

```shell
./concurrent_programming 1
Output
Depending on the test number you choose, the program will execute the corresponding test and display the result.

Please note that the actual order of the output may vary due to the asynchronous nature of the tasks.
