#include "pimpl.h"

template<typename T>
Pimpl<T>::Pimpl () : impl(new T){
  
}

template<typename T>
Pimpl<T>::~Pimpl() {

}

template<typename T>
template<typename... Args>
Pimpl<T>::pimpl(Args &&... args) : 
  impl{new T{std::forward<Args>(args)...}} {
}

template<typename T>
T *Pimple<T>::operator->() {
  return impl.get();
}

template<typename T>
T &Pimpl<T>::operator*() {
  return *impl.get();
}
