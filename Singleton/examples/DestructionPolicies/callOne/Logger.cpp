#include "Logger.h"
#include <iostream>

Logger *Logger::m_pInstance;
std::mutex Logger::m_Mtx;

Logger::Logger() {
	std::cout << "Logger::Logger() invoked" << std::endl; 
	m_pStream = fopen("applog.txt", "w");
    
    atexit([]() {
		delete m_pInstance;
	}) ;
}

std::once_flag flag;
Logger& Logger::Instance() {
    std::call_once(flag, [](int){
        m_pInstance = new Logger{};
    }, 5);

    return *m_pInstance;
}

Logger::~Logger() {
	std::cout << "Logger::~Logger() invoked" << std::endl; 
	fclose(m_pStream);
}

void Logger::WriteLog(const char* pMessage){
	fprintf(m_pStream, "[%s] %s\n", m_Tag.c_str(), pMessage);
	fflush(m_pStream);
}

void Logger::SetTag(const char* pTag) {
	m_Tag = pTag;
}
