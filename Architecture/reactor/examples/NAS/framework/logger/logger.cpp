#include <fstream>
#include <unistd.h>
#include <functional>
#include <sstream>
#include <ctime>

#include "singleton.hpp"
#include "logger.hpp"

namespace ilrd
{

using namespace std;

Logger* GetLoggerSingleton()
{
    return (Singleton<Logger>::Instance());
}

Logger::Logger(Severity initialSeverity, shared_ptr<ostream> output)
    : m_dtorFlag(false),
      m_outputSeverity(initialSeverity),
      m_output(output),
      m_qMutex(),
      m_logMsgQ()
{
    m_thread = thread(&Logger::ThreadFlushMsgs, this);
}

Logger::~Logger()
{
    m_dtorFlag = 1;
    m_thread.join();
}

void Logger::Log(Severity msgSeverity, const string &msg)
{
    unique_lock<mutex> lock(m_qMutex);
    if (msgSeverity >= m_outputSeverity)
    {
        stringstream newMsg;
        newMsg << "\n" << GetSeverName(msgSeverity) << " | " << GetCurrTimeStr()
                << " | " << msg;

        m_logMsgQ.push(newMsg.str());
    }
}

string Logger::GetCurrTimeStr() const
{
    time_t now = time(0);
    string str (ctime(&now));

    str.erase(str.end() - 1);

    return str;
}

void Logger::SetOutput(shared_ptr<ostream> output)
{
    FlushMsgs();
    m_output = output;
}

void Logger::SetOutputSeverity(Severity outputSeverity)
{
    m_outputSeverity = outputSeverity;
}

string Logger::GetSeverName(Severity sever) const
{
    const string ERROR_NAME = "ERROR  ";
    const string WARNING_NAME = "WARNING";
    const string INFO_NAME = "INFO   ";
    const string DEBUG_NAME = "DEBUG  ";

    switch (sever)
    {
    case (DEBUG):
    {
        return (DEBUG_NAME);
        break;
    }
    case (INFO):
    {
        return (INFO_NAME);
        break;
    }
    case (WARNING):
    {
        return (WARNING_NAME);
        break;
    }
    case (ERROR):
    {
        return (ERROR_NAME);
        break;
    }
    }

    return 0;
}

bool Logger::IncreaseSeverity()
{
    if (m_outputSeverity == ERROR)
    {
        cout << "ERROR is the highest severity" << endl;

        return false;
    }

    int severInt = m_outputSeverity;
    ++severInt;
    m_outputSeverity = static_cast<Logger::Severity>(severInt);
    string newSeverity = GetSeverName(m_outputSeverity);

    cout << "Severity increased to: " << newSeverity << endl;

    return true;
}

bool Logger::DecreaseSeverity()
{
    if (m_outputSeverity == DEBUG)
    {
        cout << "DEBUG is the lowest severity" << endl;

        return false;
    }

    int severInt = m_outputSeverity;
    --severInt;
    m_outputSeverity = static_cast<Logger::Severity>(severInt);

    string newSeverity = GetSeverName(m_outputSeverity);

    cout << "Severity decreased to: " << newSeverity << endl;

    return true;
}

void Logger::FlushMsgs()
{
    unique_lock<mutex> lock(m_qMutex);
    size_t qSize = m_logMsgQ.size();

    for (size_t i = 0; i < qSize; ++i)
    {
        *m_output << m_logMsgQ.front() << endl;
        m_logMsgQ.pop();
    }
}

void Logger::ThreadFlushMsgs()
{
    while (!m_dtorFlag)
    {
        FlushMsgs();

        sleep(1);
    }

    FlushMsgs();
}

} // namespace ilrd