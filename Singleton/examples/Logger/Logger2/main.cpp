#include "Logger.h"
#include <iostream>
void OpenConnection() {
	//Logger lg = Logger::Instance() ;
	Logger &lg = Logger::Instance();
	lg.WriteLog("Attempting to open a connection");
}

int main() {
	std::cout << "main() invoked" << std::endl;
  //Logger lg = Logger::Instance();
	Logger &lg = Logger::Instance();
  lg.SetTag("192.168.1.101");
	lg.WriteLog("Application has started");
	
  OpenConnection();
  lg.WriteLog("Application is shutting down");
}
