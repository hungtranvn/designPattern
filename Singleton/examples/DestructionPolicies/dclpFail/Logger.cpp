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

// static method can only acess static member => mutex object has to be
// static.
Logger& Logger::Instance() {
    if(m_pInstance == nullptr){ // double-check locking pattern
        m_Mtx.lock();
	    if(m_pInstance == nullptr){
            /*
            void *p = operator new (sizeof(Logger));
            new(p)Logger{};
            m_pInstance = static_cast<Logger*>(p);
            */

            void *p = operator new (sizeof(Logger));
            m_pInstance = static_cast<Logger*>(p);
            new(p)Logger{};

        }
	    m_Mtx.unlock();
    }
    return *m_pInstance ;
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

/*
 *void *p = operator new (sizeof(Logger));
 *new(p)Logger{};
 *m_pInstance = static_cast<Logger*>(p);
 *
 * */
