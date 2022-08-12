#ifndef RD70_FACTORY
#define RD70_FACTORY

#include <iostream>
#include <map>
#include <cassert>

namespace ilrd
{

// Template limitations:
// HANDLE - copyable
// KEY - comparable, copyable
// DATA - copyable
// CREATOR - callable (input - DATA, return - HANDLE)
template <typename HANDLE, typename KEY, typename DATA,
                                            typename CREATOR = HANDLE (*)(DATA)>

class Factory
{
public:
    explicit Factory() {}
    // Generated Dtor
    
    Factory(const Factory&) = delete;
    Factory& operator=(const Factory&) = delete;

    // Undefined behavior for existent key
    void Add(KEY key_, CREATOR creator_);

    // Undefined behavior for nonexistent key
    HANDLE Create(KEY key_, DATA data_);

    bool IsKeyExist(KEY key_);

private:
    std::map<KEY, CREATOR> m_factoryMap;
};

template <typename HANDLE, typename KEY, typename DATA, typename CREATOR>
void Factory<HANDLE, KEY, DATA, CREATOR>::Add(KEY key_, CREATOR creator_)
{
    assert(m_factoryMap.end() == m_factoryMap.find(key_));

    m_factoryMap[key_] = creator_;
}

template <typename HANDLE, typename KEY, typename DATA, typename CREATOR>
HANDLE Factory<HANDLE, KEY, DATA, CREATOR>::Create(KEY key_, DATA data_)
{
    assert(m_factoryMap.end() != m_factoryMap.find(key_));
    
    return (m_factoryMap[key_](data_));
}

template <typename HANDLE, typename KEY, typename DATA, typename CREATOR>
bool Factory<HANDLE, KEY, DATA, CREATOR>::IsKeyExist(KEY key_)
{
    return (m_factoryMap.end() != m_factoryMap.find(key_));
}

} // namespace ilrd

#endif // RD70_FACTORY
