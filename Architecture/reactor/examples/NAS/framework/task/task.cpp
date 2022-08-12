#include "task.hpp"

namespace ilrd
{

Task::Task(int priority)
    : m_priority(priority)
{}

bool Task::operator<(Task &other)
{
    return (m_priority < other.m_priority);
}

} // namespace ilrd