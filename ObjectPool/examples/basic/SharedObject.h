#ifndef SHARED_OBJECT_H
#define SHARED_OBJECT_H
class SharedObject {
  bool m_IsUsed{true};
public:
  bool IsUsed() const {return m_IsUsed;}
  void SetUsedState(bool used) {m_IsUsed = used;}
  void Reset();
  void MethodA();
  void MethodB();
};
#endif
