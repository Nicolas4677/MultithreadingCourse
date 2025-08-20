#include <iostream>
#include <thread>

/*
 * NOTES:
 * 
 * Lesson #1: Creating and Terminating Threads:
 * - I've setup the CMake project to easily build the project
 * - I'm following the course which is made with C but following the steps in C++.
 * - Threads are pretty easy to "spawn" with C++'s standard library.
 * - I like that we can pass arguments to the thread function implementation
 */

void ThreadExecution(std::string msg);

int main(int argc, char *argv[])
{
    static constexpr int8_t threadCount = 10;
    std::thread threads[threadCount];
    for (size_t idx = 0; idx < threadCount; idx++)
    {
        threads[idx] = std::thread(ThreadExecution, "Hello World!");
    }
};

void ThreadExecution(std::string msg)
{
    std::cout << msg << std::endl;
};