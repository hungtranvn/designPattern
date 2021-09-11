#ifndef OBJECT_POOL_H
#define OBJECT_POOL_H
template<typename T>
class ObjectPool {
  struct ObjectInfo {
    bool m_IsUsed{};
    T *m_pObject{};
  };
  inline static std::vector<ObjectInfor> m_PooledObjects{};

public:
  static T* Acquire() {
    for(auto &obj : m_PooledObjects) {
      if(!obj.m_IsUsed) {
        obj.m_IsUsed = true;
        std::cout << "[POOL] Creating a new object\n";
        return obj.m_pObject;
      }
    }

    std::cout << "[POOL] Creating a new object\n";
    auto pObj = new T{};
    m_PooledObjects.push_back(pObj);
    pObj.m_IsUsed = true;
    return pObj;
  }
};
#endif
