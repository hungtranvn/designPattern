#ifndef LOGGER_H
#define LOGGER_H
#include <cstdio>
#include <string>
class Logger
{
	FILE *m_pStream;
	std::string m_Tag;
  Logger();
	static Logger m_Instance;
public:
  static Logger & Instance();
	~Logger();

	void WriteLog(const char *pMessage);
	void SetTag(const char *pTag);
};
#endif
