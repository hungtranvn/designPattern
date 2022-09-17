#include <cstring>      // memset
#include <sys/types.h>  // sendto
#include <sys/socket.h> // socket
#include <netinet/in.h> // sockaddr_in
#include <fstream>      // ofstream
#include <errno.h>

#include "writer.hpp"
#include "singleton.hpp"
#include "logger.hpp"

namespace ilrd
{

using namespace std;

Writer::Writer(int sockfd, char *buff, sa_i *cliAddr)
    : RWCmd(sockfd, buff), m_cliAddr(cliAddr), m_logger(GetLoggerSingleton())
{}

bool Writer::operator()()
{
    WriteToFile();
    Send();
    
    return true;
}

void Writer::WriteToFile()
{
    char *statusPtr = m_buff + 9;
    char *dataPtr = m_buff + 17;

    m_logger->Log(Logger::INFO, "Write request was accepted.");
    *statusPtr = '1';

    FILE *wFptr = fopen(m_fullname.c_str(), "w");
    if (nullptr == wFptr)
    {
        cerr << "\nFunction: " << __func__ << "(): " << strerror(errno) << endl;
        m_logger->Log(Logger::ERROR, m_fullname + " wasn't opened successfully.");
        *statusPtr = '0';
    }
    else
    {
        m_logger->Log(Logger::INFO, m_fullname + " was opened succeessfully");
    }

    size_t writtenBytes = fwrite(dataPtr, sizeof(char), RWCmd::BUFF_LEN, wFptr);
    if (RWCmd::BUFF_LEN != writtenBytes)
    {
        m_logger->Log(Logger::ERROR, "Missing written bytes.");
        *statusPtr = '0';
    }

    fclose(wFptr);
    m_logger->Log(Logger::INFO, "Writing request is completed.");
}

void Writer::Send()
{
    size_t writer_buff_s = 10;
    size_t length = sizeof(sa_i);

    int status = sendto(m_sockfd, m_buff, writer_buff_s, MSG_CONFIRM,
                        (const struct sockaddr *)m_cliAddr, length);
    
    if (-1 == status)
    {
        cerr << "\nFunction: " << __func__ << "(): " << strerror(errno) << endl;
        m_logger->Log(Logger::ERROR, "Writer: send() failed");
    }
    else
    {
        m_logger->Log(Logger::INFO, "Writer: send() succeeded");
    }
}

shared_ptr<Command> CreateCmd(void *sendData)
{
    SendData *sendDataPtr = reinterpret_cast<SendData *>(sendData);
    
    return (shared_ptr<Command>(new Writer(sendDataPtr->GetSockfd(),
                    sendDataPtr->GetBuffer(), sendDataPtr->GetClientAddr())));
}

char GetKey()
{
    return 1;
}

} // namespace ilrd