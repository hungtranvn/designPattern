#include "Logger.h"
#include <iostream>
Logger *Logger::m_pInstance;
std::mutex Logger::m_Mtx;
Logger::Logger() {
	std::cout << "Logger::Logger()" << std::endl; 
	m_pStream = fopen("applog.txt", "w");
  atexit([]() {
		delete m_pInstance;
	});
}
Logger& Logger::Instance() {
	m_Mtx.lock();
  if(m_pInstance == nullptr)
		m_pInstance = new Logger{};
  m_Mtx.unlock();
  return *m_pInstance;
}
Logger::~Logger() {
	std::cout << "Logger::~Logger()" << std::endl; 
	fclose(m_pStream);
}
void Logger::WriteLog(const char* pMessage){
	fprintf(m_pStream, "[%s] %s\n", m_Tag.c_str(), pMessage);
	fflush(m_pStream);
}
void Logger::SetTag(const char* pTag) {
	m_Tag = pTag;
}
