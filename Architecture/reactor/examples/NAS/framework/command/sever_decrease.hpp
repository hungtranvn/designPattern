#ifndef RD70_SEVER_DECREASE
#define RD70_SEVER_DECREASE

#include "log_cmd.hpp"

namespace ilrd
{

class SeverityDecrease : public LogCmd
{
public:
    virtual bool operator()();
};

} //namespace ilrd

#endif // RD70_SEVER_DECREASE
