#ifndef RD70_THREADPOOL
#define RD70_THREADPOOL

#include <iostream>     // std
#include <queue>
#include <thread>
#include <vector>
#include <mutex>
#include <memory>

#include "task.hpp"
#include "waitable_queue.hpp"

namespace ilrd
{

class ThreadPool
{
public:
    explicit ThreadPool(int threadsNum_);
    ~ThreadPool();

    // SHOULD BLOCK CCTOR & ASSIGNMENT OP?

    void AddTask(std::shared_ptr<Task> task_);
    void Pause();
    void Resume();

private:
    void PullTasks();

    std::vector<std::thread> m_threadsVec;
    WaitableQ< std::shared_ptr<Task> > m_q;
    bool m_stopPullTasks;
    std::mutex m_pauseMutex;


    class DoNothingTask: public Task
    {
    public:
        explicit DoNothingTask(int priority_);

        virtual ~DoNothingTask(){}
        virtual void Execute();
    };


    class PauseTask: public Task
    {
    public:
        explicit PauseTask(int priority_, std::mutex *m_);

        virtual ~PauseTask() {}
        virtual void Execute();
    
    private:
        std::mutex *m_pauseMutexPtr;
    };
};

bool operator<(std::shared_ptr<Task>, std::shared_ptr<Task>);

} // namespace ilrd

#endif // RD70_THREADPOOL