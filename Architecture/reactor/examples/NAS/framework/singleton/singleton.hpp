#ifndef RD70_SINGLETON
#define RD70_SINGLETON

#include <iostream>

namespace ilrd
{

template <typename T>
class Singleton
{
public:
    static T* Instance();

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    explicit Singleton(){};
};

template <typename T>
T *Singleton<T>::Instance()
{
    static T instance;

    return &instance;
}

} // namespace ilrd

#endif // RD70_SINGLETON