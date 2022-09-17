#ifndef RD70_WAITABLE_QUEUE
#define RD70_WAITABLE_QUEUE

#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>

namespace ilrd
{

template <typename TASK>
class WaitableQ
{
public:
    explicit WaitableQ();
    ~WaitableQ() = default;

    WaitableQ(const WaitableQ& wq) = delete;
    WaitableQ& operator=(const WaitableQ& wq) = delete;

    TASK Pop();
    void Push(TASK& item_);
    bool IsEmpty() const;
    
private:
    std::priority_queue<TASK, std::vector<TASK>, std::greater<TASK> > m_tasksQ;
    std::mutex m_tasksQMutex;
    std::condition_variable m_taskAvailableCV;
};

template <typename TASK>
WaitableQ<TASK>::WaitableQ()
    : m_tasksQ(), m_tasksQMutex(), m_taskAvailableCV()
{}

template <typename TASK>
TASK WaitableQ<TASK>::Pop()
{
    std::unique_lock<std::mutex> lock(m_tasksQMutex);
    
    while (m_tasksQ.empty())
    {
        m_taskAvailableCV.wait(lock);
    }
    
    TASK task = m_tasksQ.top();
    m_tasksQ.pop();

    return task;
}

template <typename TASK>
void WaitableQ<TASK>::Push(TASK& item)
{
    std::unique_lock<std::mutex> lock(m_tasksQMutex);
    m_tasksQ.push(item);
    lock.unlock();
    m_taskAvailableCV.notify_one();
}

template <typename TASK>
bool WaitableQ<TASK>::IsEmpty() const
{
    return m_tasksQ.empty();
}


} // namespace ilrd

#endif // RD70_WAITABLE_QUEUE