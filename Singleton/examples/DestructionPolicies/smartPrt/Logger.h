#ifndef LOGGER_H
#define LOGGER_H

#include <cstdio>
#include <string>
#include <memory>

class Logger {
  struct Deleter {
    void operator()(Logger *p) {
      delete p;
    }
  };
	FILE *m_pStream;
	std::string m_Tag;
  Logger();
	inline static std::unique_ptr<Logger, Deleter> m_pInstance {};
	~Logger();
public:
  Logger(const Logger&) = delete;
	Logger & operator=(const Logger &) = delete;
  static Logger & Instance();
  void WriteLog(const char *pMessage);
	void SetTag(const char *pTag);
};
#endif
