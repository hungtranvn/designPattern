#include "Logger.h"
#include <thread>

void OpenConnection() {
	Logger &lg = Logger::Instance();
	lg.WriteLog("Attempting to open a connection");
}

int main() {
    std::thread t1{[](){
        Logger &lg = Logger::Instance();
        lg.WriteLog("Thread 1 has started!");
        }
    };
    
    std::thread t2{[](){
        Logger &lg = Logger::Instance();
        lg.WriteLog("Thread 2 has started!");
        }
    };

    t1.join();
    t2.join();

    return 0;
}
