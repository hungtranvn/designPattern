#ifndef LOGGER_H
#define LOGGER_H

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <mutex>

class Logger
{   
    static std::mutex m_Mtx;
    FILE *m_pStream;
	std::string m_Tag;
	Logger();
	static Logger *m_pInstance;
	~Logger();

public:
	Logger(const Logger&) = delete;
	Logger & operator =(const Logger &) =delete;
	
    static Logger & Instance();
	void WriteLog(const char *pMessage);
	void SetTag(const char *pTag);
};
#endif
