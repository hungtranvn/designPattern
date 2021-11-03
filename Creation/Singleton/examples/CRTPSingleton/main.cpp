#include "BaseSingleton.h"
#include "Logger.h"
#include <thread>

class GameManager : public BaseSingleton<GameManager> {
private:
  GameManager() = default;
  friend class BaseSingleton<GameManager>;
public:
	void LoadAssets() {
		
	}
	void Run() {
		
	}
};

void OpenConnection() {
	Logger &lg = Logger::Instance();
	lg.WriteLog("Attempting to open a connection");
}

int main() {
	GameManager &gm = GameManager::Instance();
	//auto gm2 = gm;
	gm.LoadAssets(); 
	
	std::thread t1{[]() {
		Logger &lg = Logger::Instance();
		lg.WriteLog("Thread 1 has started");
	}};
	
    std::thread t2{[]() {
		Logger &lg = Logger::Instance();
		lg.WriteLog("Thread 2 has started");
	}};

	t1.join();
	t2.join();
}
