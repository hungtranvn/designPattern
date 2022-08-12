#include <iostream>
#include <unistd.h>
#include <functional>
#include <cstring>
#include <errno.h>

#include "logger.hpp"
#include "singleton.hpp"
#include "plugin_loader.hpp"
#include "new_file_notifier.hpp"

namespace ilrd
{

using namespace std;

NewFileNotifier::NewFileNotifier(std::string pathToTrack)
    : m_dirMonitorFD(0), m_pathToTrack(pathToTrack),
      m_dirMonitor(pathToTrack, &m_dirMonitorFD), 
      m_reactor(*Singleton<Reactor>::Instance())
{
    m_dispatcher = Singleton<Dispatcher<string>>::Instance();
    auto notifyNewFile = bind(&NewFileNotifier::NotifyNewFile, this);
    m_reactor.AddFD(make_pair(m_dirMonitorFD, FDListener::READ), notifyNewFile);
}

NewFileNotifier::~NewFileNotifier()
{
    m_reactor.RemoveFD(make_pair(m_dirMonitorFD, FDListener::READ));
    close(m_dirMonitorFD);
}

void NewFileNotifier::NotifyNewFile()
{
    int totalRead = read(m_dirMonitorFD, m_buff, BUFFER_LEN);
    CheckRes(totalRead, "read() failed.");
    
    int i = 0;
    while (i < totalRead)
    {
        struct inotify_event *event = (struct inotify_event *)&m_buff[i];

        m_dispatcher->NotifyAll(m_pathToTrack + event->name);
        LogEvent(event);

        i += MONITOR_EVENT_SIZE + event->len;
    }
}

void NewFileNotifier::Register(CallbackBase<string> *cb)
{
    m_dispatcher->Register(cb);
}

void NewFileNotifier::Unregister(CallbackBase<string> *cb)
{
    m_dispatcher->Unregister(cb);
}

void NewFileNotifier::CheckRes(int ret, string msg)
{
    if (-1 == ret)
    {
        GetLoggerSingleton()->Log(Logger::ERROR, msg + "\n" + strerror(errno));
        cerr << "\nDirMonitor: " << strerror(errno) << endl;
    }
}

void NewFileNotifier::LogEvent(struct inotify_event *event)
{
    Logger *logger = GetLoggerSingleton();

    if (event->mask & IN_CREATE)
    {
        if (event->mask & IN_ISDIR)
        {
            logger->Log(Logger::INFO, "Directory \"" +
                        static_cast<string>(event->name) + "\" was created\n");

            cout << "\nDirectory \"" << event->name << "\" was created\n"
                 << endl;
        }
        else
        {
            logger->Log(Logger::INFO, "File \"" +
                        static_cast<string>(event->name) + "\" was created\n");

            cout << "\nFile \"" << event->name << "\" was created\n"
                 << endl;
        }
    }
}

} // namespace ilrd
