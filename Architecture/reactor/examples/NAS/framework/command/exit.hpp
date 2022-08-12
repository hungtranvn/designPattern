#ifndef RD70_EXIT
#define RD70_EXIT

#include "command.hpp"

namespace ilrd
{

class Exit : public Command
{
public:
    virtual bool operator()();
};

} //namespace ilrd

#endif // RD70_EXIT
