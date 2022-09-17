#include <functional>

#include "sever_increase.hpp"
#include "sever_decrease.hpp"
#include "exit.hpp"
#include "stdin_handler.hpp"

namespace ilrd
{

using namespace std;

void StdinHandler::HandleStdin()
{
    string input("");
    void* nlpt = nullptr;
    
    stdinFact_t cmdFactory;
    SetFact(&cmdFactory);

    cin >> input;

    if ( !IsInputValid(input) )
    {
        cout << "Invalid input!\n Valid inputs: +, -, exit\n\n Try again:" 
            << endl;
        cin >> input;
    }
    else
    {
        shared_ptr<Command> cmd = cmdFactory.Create(input, nlpt);
        (*cmd)();
    }
}

bool StdinHandler::IsInputValid(string input)
{
    return (0 == input.compare("+") ||
            0 == input.compare("-") ||
            0 == input.compare("exit"));
}

shared_ptr<Command> StdinHandler::CreateIncSev(void *)
{
    return (shared_ptr<Command>(new SeverityIncrease));
}

shared_ptr<Command> StdinHandler::CreateDecSev(void *)
{
    return (shared_ptr<Command>(new SeverityDecrease));
}

shared_ptr<Command> StdinHandler::CreateExit(void *)
{
    return (shared_ptr<Command>(new Exit));
}

void StdinHandler::SetFact(stdinFact_t *fact)
{
    string key1 = "+";
    string key2 = "-";
    string key3 = "exit";

    using placeholders::_1;
    auto createIncSev = bind(&StdinHandler::CreateIncSev, this, _1);
    auto createDecSev = bind(&StdinHandler::CreateDecSev, this, _1);
    auto createExit = bind(&StdinHandler::CreateExit, this, _1);
                        
    fact->Add(key1, createIncSev);
    fact->Add(key2, createDecSev);
    fact->Add(key3, createExit);
}

} // namespace ilrd