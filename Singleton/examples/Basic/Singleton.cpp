#include <iostream>
#include "Singleton.h"

Singleton Singleton::m_Instance ;
Singleton& Singleton::Instance() {
  std::cout << "Static instance was created!\n";
	return m_Instance ;
}

void Singleton::MethodA() {
}

void Singleton::MethodB() {
}
