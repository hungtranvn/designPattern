#ifndef LOGGER_H
#define LOGGER_H

#include <cstdio>
#include <string>

class Logger
{
	FILE *m_pStream; // file IO
	std::string m_Tag;
	
  Logger();
	static Logger m_Instance;
public:
	//Logger(const Logger&) = delete;
	//Logger & operator =(const Logger &) = delete;
  static Logger & Instance();
	~Logger();

	void WriteLog(const char *pMessage); // write on the log file
	void SetTag(const char *pTag);
};
#endif
