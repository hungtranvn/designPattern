#ifndef OBJECT_POOL_H
#define OBJECT_POOL_H
#include <vector>
#include <memory>
class SharedObject;

class ObjectPool {
  ObjectPool() = default;
  inline static std::vector<std::shared_ptr<SharedObject>> m_PooledObjects{};
public:
  static std::shared_ptr<SharedObject> AcquireObject();
  static void ReleaseObject(std::shared_ptr<SharedObject> pSO);
};
#endif
