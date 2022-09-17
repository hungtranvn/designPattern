#include <algorithm>

#include "threadpool.hpp"

namespace ilrd
{

using namespace std;

ThreadPool::ThreadPool(int threadsNum)
    : m_threadsVec(), m_q(), m_stopPullTasks(false)
{
    for (int i = 0; i < threadsNum; ++i)
    {
        m_threadsVec.push_back(thread(&ThreadPool::PullTasks, this));
    }
}

ThreadPool::~ThreadPool()
{
    m_stopPullTasks = true;
    size_t threadsNum = m_threadsVec.size();
    shared_ptr<Task> doNothingTask(new ThreadPool::DoNothingTask(-1));

    for (size_t i = 0; i < threadsNum; ++i)
    {
        m_q.Push(doNothingTask);
    }

    for_each(m_threadsVec.begin(), m_threadsVec.end(), [](thread& t)
    {
        t.join();
    });
}


void ThreadPool::PullTasks()
{
    while (!m_stopPullTasks)
    {
        shared_ptr<Task> task = m_q.Pop();
        task->Execute();
    }
}

void ThreadPool::AddTask(shared_ptr<Task> task)
{
    m_q.Push(task);
}

ThreadPool::DoNothingTask::DoNothingTask(int priority)
    : Task(priority)
{}

void ThreadPool::DoNothingTask::Execute()
{
    return;
}

ThreadPool::PauseTask::PauseTask(int priority, std::mutex *m_)
    : Task(priority), m_pauseMutexPtr(m_)
{}

void ThreadPool::PauseTask::Execute()
{
    std::unique_lock<std::mutex> lock(*m_pauseMutexPtr);
}

void ThreadPool::Pause()
{
    size_t threadsNum = m_threadsVec.size();
    shared_ptr<Task> pauseTask(new PauseTask(-2, &m_pauseMutex));
    
    m_pauseMutex.lock();

    for (size_t i = 0; i < threadsNum; ++i)
    {
        AddTask(pauseTask);
    }
}

void ThreadPool::Resume()
{
    m_pauseMutex.unlock();
}

bool operator<(shared_ptr<Task> t1, shared_ptr<Task> t2)
{
    return (*t1 < *t2);
}

} // namespace ilrd