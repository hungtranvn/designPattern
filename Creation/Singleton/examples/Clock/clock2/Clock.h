#ifndef CLOCK_H_
#define CLOCK_H_

#include <string>
class Clock
{
  // using inline key word => do not have to define them outside class
	inline static int m_Hour;
	inline static int m_Minute;
	inline static int m_Second;
	void CurrentTime();
public:
  Clock();
	int GetHour();  
	int GetMinute();
	int GetSecond();
	std::string GetTimeString();
};
#endif // CLOCK_H
/*
 * earlier: if three instances are created => three different attributes
 * c1 - h m s
 * c2 - h m s
 * c3 - h m s
 *
 * With static attributes: same attributes
 * c1\ 
 * c2-h m s
 * c3/ 
 * 
 * 
 */
