#include <iostream>
#include <string>
#include <unistd.h>

#include "task.hpp"
#include "threadpool.hpp"

using namespace ilrd;
using namespace std;

class TaskTest : public Task
{
public:
    explicit TaskTest(int priority, std::string str);
    ~TaskTest() {}

    virtual void Execute();
    std::string GetStr();

private:
    std::string m_str;
};

TaskTest::TaskTest(int priority, string str)
    : Task(priority), m_str(str)
{}

string TaskTest::GetStr()
{
    return m_str;
}

void TaskTest::Execute()
{
    cout << GetStr() << endl;
}


int main()
{
    shared_ptr<TaskTest> task_test6(new TaskTest(6, "Hello 6!\n"));
    shared_ptr<TaskTest> task_test5(new TaskTest(5, "Hello 5!\n"));
    shared_ptr<TaskTest> task_test4(new TaskTest(4, "Hello 4!\n"));
    shared_ptr<TaskTest> task_test3(new TaskTest(3, "Hello 3!\n"));
    shared_ptr<TaskTest> task_test2(new TaskTest(2, "Hello 2!\n"));
    shared_ptr<TaskTest> task_test1(new TaskTest(1, "Hello 1!\n"));
    
    ThreadPool threadpool(5);

    threadpool.AddTask(task_test1);
    threadpool.AddTask(task_test2);
    threadpool.AddTask(task_test3);
    threadpool.AddTask(task_test4);
    threadpool.AddTask(task_test5);
    threadpool.AddTask(task_test6);

    threadpool.Pause();
    cout << "\nPause!!!" << endl;
    sleep(2);
    
    threadpool.Resume();
    sleep(2);

    return 0;
}