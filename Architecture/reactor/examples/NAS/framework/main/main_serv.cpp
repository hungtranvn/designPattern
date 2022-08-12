#include <sys/types.h>      /* sendto */
#include <arpa/inet.h>      /* htons */
#include <thread>
#include <fstream>
#include <functional>

#include "singleton.hpp"
#include "reactor.hpp"
#include "logger.hpp"
#include "sockfd.hpp"
#include "dir_monitor.hpp"
#include "new_file_notifier.hpp"
#include "udp_manager.hpp"
#include "stdin_handler.hpp"
#include "plugin_loader.hpp"
#include "config_loader.hpp"

using namespace ilrd;
using namespace std;

using cmdFact_t = Factory<shared_ptr<Command>, char, void *>;

static void InitSingletons();
static void SetUDP(int port, Reactor *reactor);

int main(int argc, char *argv[])
{
    InitSingletons();

    Reactor *reactor = Singleton<Reactor>::Instance();

    shared_ptr<ofstream> logFilePtr(new ofstream("log.txt", ios::out));
    GetLoggerSingleton()->SetOutput(logFilePtr);
    
    // int port = htons(atoi(argv[argc - 1]));
    int port = htons(8080);
    SetUDP(port, reactor);
    
    FD stdinFd = 0;
    StdinHandler stdinHandler;
    auto handleStdin = bind(&StdinHandler::HandleStdin, stdinHandler);
    reactor->AddFD(make_pair(stdinFd, FDListener::READ), handleStdin);

    reactor->Start();

    return 0;
}

static void InitSingletons()
{
    Singleton<Sockfd>::Instance();
    Singleton<Reactor>::Instance();
    Singleton<NewFileNotifier>::Instance();
    Singleton<PluginLoader>::Instance();
    Singleton<ConfigLoader>::Instance();
    Singleton<cmdFact_t>::Instance();
}

static void SetUDP(int port, Reactor *reactor)
{
    cmdFact_t *cmdFactory = Singleton<cmdFact_t>::Instance();
    UDPManager udpManager(port, *cmdFactory);
    Sockfd *sockfdPtr = Singleton<Sockfd>::Instance();

    FD sockfd = udpManager.CreateSocketAndBind();
    sockfdPtr->SetSockfd(sockfd);
    auto receiveAndHandleRequest = 
                        bind(&UDPManager::ReceiveAndHandleRequest, udpManager);
    reactor->AddFD(make_pair(sockfdPtr->GetSockfd(), FDListener::READ),
                                                        receiveAndHandleRequest);
}