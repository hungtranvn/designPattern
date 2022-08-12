#ifndef RD70_LOGGER
#define RD70_LOGGER

#include <iosfwd>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <string>

namespace ilrd
{

class Logger
{
public:
    enum Severity { DEBUG, INFO, WARNING, ERROR };

    explicit Logger(Severity initialSeverity_ = DEBUG, 
            std::shared_ptr<std::ostream> output_ = 
            std::shared_ptr<std::ostream>(new std::ostream(std::cerr.rdbuf())));
    ~Logger();

    void Log(Severity msgSeverity_, const std::string& msg_);
    void SetOutput(std::shared_ptr<std::ostream> output_);
    
    void SetOutputSeverity(Severity outputSeverity_);
    std::string GetSeverName(Severity sever_) const;
    bool IncreaseSeverity();
    bool DecreaseSeverity();
    
private:
    void FlushMsgs();
    void ThreadFlushMsgs();
    std::string GetCurrTimeStr() const;

    bool m_dtorFlag;
    Logger::Severity m_outputSeverity;
    std::shared_ptr<std::ostream> m_output;
    std::mutex m_qMutex;
    std::queue<std::string> m_logMsgQ;
    std::thread m_thread;
};

Logger *GetLoggerSingleton();

} //namespace ilrd

#endif // RD70_LOGGER
