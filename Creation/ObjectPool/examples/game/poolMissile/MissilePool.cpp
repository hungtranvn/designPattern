#include "MissilePool.h"
#include <iostream>

MissilePtr MissilePool::AcquireMissile() {
  for (auto &missile : m_Missiles) {
    missile->SetVisible(true);
    std::cout << "[POOL] returning an existing instance\n";
    return missile;
  }
  std::cout << "[POOL] creating a new instance \n";
  auto missile = std::make_shared<Missile>();
  m_Missiles.push_back(missile);
  return missile;
}

void MissilePool::ReleaseMissile(const MissilePtr& missile) {
  for (auto &m : m_Missiles) {
    if(m == missile) {
      m->SetVisible(false);
    }
  }
}
