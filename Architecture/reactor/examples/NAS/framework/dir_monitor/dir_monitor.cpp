#include <iostream>
#include <unistd.h>
#include <sys/inotify.h>
#include <cstring>
#include <errno.h>

#include "dir_monitor.hpp"
#include "logger.hpp"

namespace ilrd
{

using namespace std;

DirMonitor::DirMonitor(string path, FD *dirMonitorFdOut)
    : m_inotifyFD(-1), m_watchDesc(-1)
{
    Logger *logger = GetLoggerSingleton();

    m_inotifyFD = inotify_init();
    CheckRes(m_inotifyFD, "DirMonitor: Notify not initialize");

    int m_watchDesc = inotify_add_watch(m_inotifyFD, path.c_str(), IN_CREATE);
    CheckRes(m_watchDesc, "DirMonitor: Couldn't add watch to" + path);
    if (-1 != m_watchDesc)
    {
        logger->Log(Logger::INFO, "Monitor added to path: " + path);
    }

    *dirMonitorFdOut = m_inotifyFD;
}


DirMonitor::~DirMonitor()
{
    inotify_rm_watch(m_inotifyFD, m_watchDesc);
}

void DirMonitor::CheckRes(int ret, string msg)
{
    if (-1 == ret)
    {
        GetLoggerSingleton()->Log(Logger::ERROR, msg + "\n" + strerror(errno));
        cerr << "\nDirMonitor: " << strerror(errno) << endl;
    }
}

} // namespace ilrd