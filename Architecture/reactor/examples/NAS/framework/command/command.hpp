#ifndef RD70_COMMAND
#define RD70_COMMAND

namespace ilrd
{
class Command
{
public:

    // Default Ctor
    virtual ~Command() {}

    virtual bool operator()() = 0;
};

} // namespace ilrd

#endif // RD70_COMMAND