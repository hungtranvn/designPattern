#ifndef BASE_SINGLETON_H
#define BASE_SINGLETON_H

template<typename T>
class BaseSingleton
{
protected:
	BaseSingleton() = default;
	BaseSingleton(const BaseSingleton &) = delete;
	BaseSingleton & operator=(const BaseSingleton &) = delete;
public:
	static T& Instance() {
		static T instance;
		return instance;
	}
};
//#define MAKE_SINGLETON(class_name)private: class_name() = default;
//friend class BaseSingleton<class_name>;
#endif // BASE_SINGLETON_H
