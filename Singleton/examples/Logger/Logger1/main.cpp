#include "Logger.h"
#include <iostream>
// Create an other instance
void OpenConnection() {
  Logger lg;
  lg.WriteLog("Attempting to open a connection");
}
int main() {
  std::cout << "main() invoked" << std::endl;
  Logger lg;
  lg.SetTag("192.168.1.101");
  lg.WriteLog("Application has started");
  OpenConnection();
  lg.WriteLog("Application is shutting down");
  return 0;
}
