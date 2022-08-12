#ifndef RD70_FDLISTENER
#define RD70_FDLISTENER

#include <iostream>
#include <vector>
#include <sys/time.h>

namespace ilrd
{

using FD = int;

class FDListener
{
    
public:
    explicit FDListener() = default;
    ~FDListener() = default;
    
    enum FDType {READ, WRITE, EXCEPT};
    
    using FDPair = std::pair<FD, FDType>;

    std::vector<std::pair<FD, FDType>> Wait(std::vector<FDPair>& vec_,
                                    time_t seconds_ = 30, time_t microseconds_ = 0);
   
    void SetTimeout(time_t seconds_, time_t microseconds_);

private:
    struct timeval m_timeout;
};

} // namespace ilrd

#endif // RD70_FDLISTENER
