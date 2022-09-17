#include <string>
#include <thread>
#include <unistd.h>

#include "waitable_queue.hpp"

#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define RESET "\x1B[0m"

#define THREADS_NUM (4)

using namespace ilrd;
using namespace std;

WaitableQ<int> wq;

void Producer()
{
    int num = 10;

    wq.Push(num);

    cout << GRN << "push" << RESET << endl;
}

void Consumer()
{
    int x = wq.Pop();

    cout << RED << "pop: " << x << endl;
}

int main()
{
    thread thread1[4];
    thread thread2[4];

    for (size_t i = 0; i < THREADS_NUM; ++i)
    {
        thread1[i] = thread(Producer);
        thread2[i] = thread(Consumer);
    }

    for (size_t i = 0; i < THREADS_NUM; ++i)
    {
        thread1[i].join();
        thread2[i].join();
    }

    return 0;
}
