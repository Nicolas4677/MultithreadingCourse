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
 * 
 * Lesson #2: Joining and Detaching Threads
 * - std::thread::join -> Calling thread will wait till termination of called thread.
 * - std::thread::detach -> Separates execution of the thread, allowing to continue execution until the thread gets terminated.
 * - std::terminate (called from respective thread) -> Terminates the calling thread
 * - Join is a blocking operation, so I'm curious how to make this async work not be blocking
 * 
 * Lesson #3: Passing Arguments to Threads
 * - Unlike C, in C++ it's way easier to pass arguments to threads. So, since the first lesson I had already added argumens.
 * - Unlike in the video, instead of getting different numbers, I seem to only get number 9 (the last index). I wonder why this is...
 */

 struct MyThreadArgs
 {
    int m_myInt = 0;
 };

void ThreadExecution(const MyThreadArgs* args);

int main(int argc, char *argv[])
{
    static constexpr int8_t threadCount = 10;
    std::thread threads[threadCount];

    MyThreadArgs threadArgs;
    for (size_t idx = 0; idx < threadCount; idx++)
    {
        threadArgs.m_myInt = idx;
        threads[idx] = std::thread(ThreadExecution, &threadArgs);
    }

    for (size_t idx = 0; idx < threadCount; idx++)
    {
        threads[idx].join();
    }
};

void ThreadExecution(const MyThreadArgs* args)
{
    std::cout << args->m_myInt << std::endl;
};