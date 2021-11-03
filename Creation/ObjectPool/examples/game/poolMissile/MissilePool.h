#ifndef MISSILE_POOL_H
#define MISSILE_POOL_H
#include <memory>
#include <vector>
#include "Missile.h"
using MissilePtr = std::shared_ptr<Missile>;
class MissilePool {
  inline static std::vector<MissilePtr> m_Missiles{};
  MissilePool() = default;
public:
  static MissilePtr AcquireMissile();
  static void ReleaseMissile(const MissilePtr& missile);
};
#endif
