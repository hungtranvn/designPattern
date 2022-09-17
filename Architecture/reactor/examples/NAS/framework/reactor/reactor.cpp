#include <algorithm>
#include <iostream>

#include "reactor.hpp"

using namespace std;

namespace ilrd
{

Reactor::Reactor()
    : m_runFlag(true)
{}

void Reactor::AddFD(FDPair fdPair, function<void(FD)> fdFunc)
{
    m_fdFuncsMap[fdPair] = fdFunc;
}

void Reactor::RemoveFD(FDPair fdPair)
{
    m_fdFuncsMap.erase(fdPair);
}

void Reactor::Start()
{
    FDListener fdListener;

    while (m_runFlag)
    {
        vector<FDPair> fdFuncsVec;
        
        for (map<FDPair, std::function<void(FD)>>::iterator it = 
                    m_fdFuncsMap.begin(); it != m_fdFuncsMap.end(); ++it)
        {
            fdFuncsVec.push_back(it->first);
        }
       
        vector<FDPair> clientFDVec(fdListener.Wait(fdFuncsVec));
        
        for_each(clientFDVec.begin(), clientFDVec.end(), [&](FDPair fdPair)
        {
            (m_fdFuncsMap[fdPair])(fdPair.first);
        });
    }
}

void Reactor::Stop()
{
    m_runFlag = false;
}


} // namespace ilrd
