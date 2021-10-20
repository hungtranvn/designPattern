#ifndef CLOCK_H_
#define CLOCK_H_
#include <string>
class Clock {
	int m_Hour;
	int m_Minute;
	int m_Second;
	void CurrentTime();
public:
  Clock();
	int GetHour();  
	int GetMinute();
	int GetSecond();
	std::string GetTimeString();
};
#endif // CLOCK_H
