#ifndef RD70_DIR_MONITOR
#define RD70_DIR_MONITOR

#include <iostream>

#include "reactor.hpp"

namespace ilrd
{

class DirMonitor
{
public:
    explicit DirMonitor(std::string path_, FD *dirMonitorFdOut_);
    ~DirMonitor();

private:
    void CheckRes(int ret_, std::string msg_);

    FD m_inotifyFD;
    int m_watchDesc;
};

} // namespace ilrd

#endif // RD70_DIR_MONITOR
