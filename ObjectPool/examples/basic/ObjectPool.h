#ifndef OBJECT_POOL_H
#define OBJECT_POOL_H
#include <vector>
class SharedObject;

class ObjectPool {
  ObjectPool() = default;
  inline static std::vector<SharedObject*> m_PooledObjects{};
public:
  static SharedObject *AcquireObject();
  static void ReleaseObject(SharedObject *pSO);
};
#endif
