#ifndef LOGGER_H
#define LOGGER_H
#include <cstdio>
#include <string>
class Logger {
  FILE *m_pStream;
  std::string m_Tag;
public:
  Logger();
  ~Logger();
  void WriteLog(const char *pMessage);
  void SetTag(const char *pTag);
};
#endif
