#include <algorithm>
#include <sys/select.h>
#include <map>
#include <cstring>
#include <errno.h>

#include "fdlistener.hpp"

namespace ilrd
{

using namespace std;

vector<pair<FD, FDListener::FDType>> FDListener::Wait(
    vector<FDPair> &vec, time_t seconds, time_t microseconds)
{
    FD maxSocketFd = 0;
    map<FDListener::FDType, fd_set> FDMap;
    int activity = 0;

    FD_ZERO(&FDMap[READ]);
    FD_ZERO(&FDMap[WRITE]);
    FD_ZERO(&FDMap[EXCEPT]);

    m_timeout.tv_sec = seconds;
    m_timeout.tv_usec = microseconds;

    for_each(vec.begin(), vec.end(), [&](FDPair pair)
    {
        FD_SET(pair.first, &FDMap[pair.second]);

        if (pair.first > maxSocketFd)
        {
            maxSocketFd = pair.first;
        }
    });

    activity = select(maxSocketFd + 1, &FDMap[READ], &FDMap[WRITE], 
                                                    &FDMap[EXCEPT], &m_timeout);
    if ((activity < 0) && (errno != EINTR))
    {
        cerr << "\nFunction: " << __func__ << "(): " << strerror(errno) << endl;
    }

    vector<pair<FD, FDListener::FDType>> retVec;

    for_each(vec.begin(), vec.end(), [&](pair<FD, FDType> pair)
    {
        if (FD_ISSET(pair.first, &FDMap[pair.second]))
        {
            retVec.push_back(pair);
        }
    });

    return retVec;
}

void FDListener::SetTimeout(time_t seconds, time_t microseconds)
{
    m_timeout.tv_sec = seconds;
    m_timeout.tv_usec = microseconds;
}

} // namespace ilrd