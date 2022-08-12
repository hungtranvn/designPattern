#ifndef RD70_NEW_FILE_NOTIFIER
#define RD70_NEW_FILE_NOTIFIER

#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <sys/inotify.h>

#include "command.hpp"
#include "reactor.hpp"
#include "dispatcher.hpp"
#include "dir_monitor.hpp"

namespace ilrd
{

using FD = int;

class NewFileNotifier
{
public:
    explicit NewFileNotifier(std::string pathToTrack = 
            std::string("/home/student/Desktop/so/")); // WARNING! For Singleton Usage only!
    ~NewFileNotifier();
    
    // Generated CCtor;
    // Generated assignment operator;

    void NotifyNewFile();
    void Register(CallbackBase<std::string> *);
    void Unregister(CallbackBase<std::string> *);

private:
    void CheckRes(int ret_, std::string msg_);
    void LogEvent(struct inotify_event *event_);

    static const size_t MAX_EVENT_MONITOR = 2048;
    static const size_t MONITOR_EVENT_SIZE = sizeof(struct inotify_event); // size of one event
    static const size_t NAME_LEN = 32;                                // file name length
    static const size_t BUFFER_LEN = MAX_EVENT_MONITOR * (MONITOR_EVENT_SIZE 
                                                                    + NAME_LEN);
    int m_dirMonitorFD;
    std::string m_pathToTrack;
    DirMonitor m_dirMonitor;
    Reactor& m_reactor;
    Dispatcher<std::string> *m_dispatcher;
    
    char m_buff[BUFFER_LEN];
};

} // namespace ilrd

#endif // RD70_NEW_FILE_NOTIFIER