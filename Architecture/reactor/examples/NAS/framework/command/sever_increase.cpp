#include "sever_increase.hpp"
#include "logger.hpp"
#include "singleton.hpp"

namespace ilrd
{

bool SeverityIncrease::operator()()
{
    return m_logger->IncreaseSeverity();
}

} // namespace ilrd