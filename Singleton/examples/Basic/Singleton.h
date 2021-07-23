class Singleton
{
	Singleton() = default; // faster than user-define
	static Singleton m_Instance ;
public:
	static Singleton & Instance() ;
	void MethodA() ;
	void MethodB() ;
};

