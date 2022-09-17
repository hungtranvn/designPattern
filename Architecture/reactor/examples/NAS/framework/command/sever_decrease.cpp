#include "sever_decrease.hpp"
#include "logger.hpp"
#include "singleton.hpp"

namespace ilrd
{

bool SeverityDecrease::operator()()
{
    return m_logger->DecreaseSeverity();
}

} // namespace ilrd