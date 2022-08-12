#include <stdlib.h>

#include "exit.hpp"
#include "singleton.hpp"
#include "reactor.hpp"

namespace ilrd
{

bool Exit::operator()()
{
    Reactor *reactor = Singleton<Reactor>::Instance();
    reactor->Stop();

    return true;
}

} // namespace ilrd