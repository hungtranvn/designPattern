#include <cstring>      // memset
#include <sys/types.h>  // sendto
#include <sys/socket.h> // socket
#include <netinet/in.h> // sockaddr_in
#include <fstream>      // ofstream
#include <errno.h>

#include "reader.hpp"
#include "singleton.hpp"
#include "logger.hpp"

namespace ilrd
{

using namespace std;

Reader::Reader(int sockfd, char *buff, sa_i *cliAddr)
    : RWCmd(sockfd, buff), m_cliAddr(cliAddr), m_logger(GetLoggerSingleton())
{}

bool Reader::operator()()
{
    ReadFromFile();
    Send();

    return true;
}

void Reader::ReadFromFile()
{
    char *statusPtr = m_buff + 9;
    char *dataPtr = m_buff + 10;

    m_logger->Log(Logger::INFO, "Read request was accepted.");
    *statusPtr = '1';

    FILE *rFptr = fopen(m_fullname.c_str(), "r");
    if (nullptr == rFptr)
    {
        cerr << "\nFunction: " << __func__ << "(): " << strerror(errno) << endl;
        m_logger->Log(Logger::ERROR, m_fullname + " wasn't opened successfully.");
        *statusPtr = '0';
    }
    else
    {
        m_logger->Log(Logger::INFO, m_fullname + " was opened succeessfully.");
    }

    size_t readBytes = fread(dataPtr, sizeof(char), RWCmd::BUFF_LEN, rFptr);
    if (RWCmd::BUFF_LEN != readBytes)
    {
        m_logger->Log(Logger::ERROR, "Missing read bytes.");
        *statusPtr = '0';
    }

    fclose(rFptr);
    m_logger->Log(Logger::INFO, "Reading request is completed.");
}

void Reader::Send()
{
    size_t reader_buff_s = 4106;
    size_t length = sizeof(sa_i);

    int status = sendto(m_sockfd, m_buff, reader_buff_s, MSG_CONFIRM,
                        (const struct sockaddr *)m_cliAddr, length);
    if (-1 == status)
    {
        cerr << "\nFunction: " << __func__ << "(): " << strerror(errno) << endl;
        m_logger->Log(Logger::ERROR, "Reader: send() failed");
    }
    else
    {
        m_logger->Log(Logger::INFO, "Reader: send() succeeded");
    }                    
}

shared_ptr<Command> CreateCmd(void *sendData)
{
    SendData *sendDataPtr = reinterpret_cast<SendData *>(sendData);
    
    return (shared_ptr<Command>(new Reader(sendDataPtr->GetSockfd(),
                    sendDataPtr->GetBuffer(), sendDataPtr->GetClientAddr())));
}

char GetKey()
{
    return 0;
}

} // namespace ilrd