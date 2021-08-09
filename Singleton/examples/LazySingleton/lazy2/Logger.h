#ifndef LOGGER_H
#define LOGGER_H

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>

class Logger
{
	FILE *m_pStream;
	std::string m_Tag;
	
  Logger();
	
  static Logger *m_pInstance;
	
public:
	~Logger();
	Logger(const Logger&) = delete;
	Logger & operator =(const Logger &) =delete;
	static Logger & Instance();
	void WriteLog(const char *pMessage);
	void SetTag(const char *pTag);
};
#endif
