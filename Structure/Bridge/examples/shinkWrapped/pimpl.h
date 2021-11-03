#ifndef _PIMPL_H_
#define _PIMPL_H_

template <typename T> class Pimpl {
private:
  std::unique_ptr<T> impl;
public:
  Pimpl();
  ~Pimpl();

  template <typename ...Args> Pimpl (Args&& ...args);

  T* operator->();
  T& operator*();
}

#endif // _PIMPL_H_
