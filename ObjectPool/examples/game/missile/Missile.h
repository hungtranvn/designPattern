#ifndef MISSILE_H
#define MISSILE_H
class Missile {
  bool m_IsVisible{true};
public:
  void SetVisible(bool visible);
  bool IsVisible() const;
  Missile();
  ~Missile();
  void Update();
};
#endif
