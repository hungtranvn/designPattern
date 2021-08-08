#include "Logger.h"
#include <iostream>
Logger::Logger() {
  m_pStream = fopen("applog.txt", "w");
  std::cout << "Logger::Logger" << std::endl;
}

Logger::~Logger() {
  fclose(m_pStream);
}

void Logger::WriteLog(const char* pMessage) {
  fprintf(m_pStream, "[%s] %s\n", m_Tag.c_str(), pMessage);
  fflush(m_pStream);// to ensure that the messages are always returned to the log file
}

void Logger::SetTag(const char* pTag) {
  m_Tag = pTag;
}
