#ifndef RD70_LOG_CMD
#define RD70_LOG_CMD

#include <iostream>

#include "command.hpp"
#include "singleton.hpp"
#include "logger.hpp"

namespace ilrd
{

class LogCmd : public Command
{
public:
    explicit LogCmd(Logger *logger_ = GetLoggerSingleton());

    virtual ~LogCmd() {}

    // Generated CCtor
    // Generated assignment operator

    virtual bool operator()() = 0;

protected:
    Logger* m_logger;
};

} // namespace ilrd

#endif // RD70_LOG_CMD