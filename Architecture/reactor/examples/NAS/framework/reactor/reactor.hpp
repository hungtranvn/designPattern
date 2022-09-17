#ifndef RD70_REACTOR
#define RD70_REACTOR

#include <iostream>
#include <functional>
#include <map>

#include "fdlistener.hpp"

namespace ilrd
{

using FDPair = std::pair<FD, FDListener::FDType>;

class Reactor
{
public:
    explicit Reactor();
    ~Reactor() = default;

    Reactor(const Reactor&) = delete;
    Reactor& operator=(const Reactor&) = delete;

    void AddFD(FDPair, std::function<void(FD)>);
    void RemoveFD(FDPair);
    void Start();
    void Stop();

private:
    bool m_runFlag;
    std::map<FDPair, std::function<void(FD)>> m_fdFuncsMap;
};


} // namespace ilrd

#endif // RD70_REACTOR
