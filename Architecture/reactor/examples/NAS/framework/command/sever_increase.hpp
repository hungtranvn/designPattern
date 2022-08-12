#ifndef RD70_SEVER_INCREASE
#define RD70_SEVER_INCREASE

#include "log_cmd.hpp"

namespace ilrd
{

class SeverityIncrease : public LogCmd
{
public:
    virtual bool operator()();
};

} //namespace ilrd

#endif // RD70_SEVER_INCREASE
