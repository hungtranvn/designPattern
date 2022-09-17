#ifndef RD70_STDIN_HANDLER
#define RD70_STDIN_HANDLER

#include <iostream>
#include <memory>

#include "command.hpp"
#include "factory.hpp"

namespace ilrd
{

using sa_i = struct sockaddr_in;
using createCmdFunc = std::function<std::shared_ptr<Command>(void *)>;
using stdinFact_t = Factory<std::shared_ptr<Command>, std::string, void *, 
                                                                createCmdFunc>;

class StdinHandler
{
public:
    // Generated Ctor on purpose
    // Generated Dtor
    // Generated CCtor
    // Generated assignment operator

    void HandleStdin();
        
private:
    bool IsInputValid(std::string input_);
    void CheckRet(int ret_, std::string msg_);
    
    std::shared_ptr<Command> CreateIncSev(void *);
    std::shared_ptr<Command> CreateDecSev(void *);
    std::shared_ptr<Command> CreateExit(void *);
    void SetFact(stdinFact_t *fact_);
};

} // namespace ilrd

#endif // RD70_STDIN_HANDLER
