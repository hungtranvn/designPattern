#ifndef RD70_TASK
#define RD70_TASK

#include <iostream> // std

namespace ilrd
{

class Task
{
public:
    explicit Task(int priority_);
    virtual ~Task() {}

    Task(const Task&) = delete;
    Task& operator=(const Task&) = delete;
    
    virtual void Execute() = 0;
    virtual bool operator<(Task &other_);

private:
    int m_priority;
};

} // namespace ilrd

#endif // RD70_TASK