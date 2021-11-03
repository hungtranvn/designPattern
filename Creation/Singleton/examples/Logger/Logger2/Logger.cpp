#include "Logger.h"
#include <iostream>
Logger Logger::m_Instance;
Logger::Logger() {
	m_pStream = fopen("applog.txt", "w");
  std::cout << "Logger::Logger()" << std::endl;
}
Logger& Logger::Instance() {
	return m_Instance;
}
Logger::~Logger() {
	fclose(m_pStream);
  std::cout << "Logger::~Logger()" << std::endl;
}
void Logger::WriteLog(const char* pMessage){
	fprintf(m_pStream, "[%s] %s\n", m_Tag.c_str(), pMessage);
	fflush(m_pStream);
}
void Logger::SetTag(const char* pTag) {
	m_Tag = pTag;
}
