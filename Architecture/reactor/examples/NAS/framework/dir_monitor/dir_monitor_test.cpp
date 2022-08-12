#include <functional>

// #include "reactor.hpp"
#include "dir_monitor.hpp"
// #include "new_file_notifier.hpp"

using namespace ilrd;
using namespace std;

int main()
{
    // Reactor reactor;
    // string path = ".";
    // FD dirMonitorFD = 0;

    // DirMonitor dirMonitor(path, &dirMonitorFD);
    // NewFileNotifier pluginManager(dirMonitorFD, reactor);
    
    // using std::placeholders::_1;
    // function<void(FD)> handlePlugin = 
    //         bind(&NewFileNotifier::NotifyNewFile, pluginManager, _1);

    // reactor.AddFD(make_pair(dirMonitorFD, FDListener::READ), handlePlugin);

    // reactor.Start();

    return 0;
}
