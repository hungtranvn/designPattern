#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton
{   
  // First: disable the construction by making constructor private.
	Singleton() = default; // faster than user-define
	// Second: create the static instance of class.
  static Singleton m_Instance;
public:
  // Third: Using instance method provides m_Instance to the clients.
	static Singleton & Instance() ;
	void MethodA() ;
	void MethodB() ;
};
#endif
