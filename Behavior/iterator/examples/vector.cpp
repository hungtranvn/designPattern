#include "vector.h"

template <typename T>
DummyVector<T>::DummyVector() : mSize{0}, mBuffer{nullptr} {}

template<typename T>
DummyVector<T>::DummyVector(size_t size) : mSize{size}, mBuffer{new T[size]} {
  for (int i = 0; i < mSize; i++) {
    mBuffer[i] = 0;
  }
}

template <typename T>
DummyVector<T>::DummyVector(std::initializer_list<T> lst) : \
    mSize{lst.size()}, mBuffer{new T[lst.size()]} {
  std::copy(lst.begin(), lst.end(), this->mBuffer);
}

template<typename T>
class DummyVector<T>::Iterator {
public:
  Iterator(T* ptr);
  Iterator& operator++();
  Iterator& operator--();
}
