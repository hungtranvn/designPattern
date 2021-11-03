#include "Singleton.h"

int main() {
	Singleton &s = Singleton::Instance() ;
	s.MethodA() ;

	//Singleton s2 ;
}
