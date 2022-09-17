#ifndef _DUMMY_VECTOR_H_
#define _DUMMY_VECTOR_H_

template <typename T>

class DummyVector {
public:
  DummyVector();
  explicit DummyVector(size_t size);
  explicit DummyVector(std::initializer_list<T> lst);
  
  class Iterator;
  Iterator begin();
  Iterator end();
private:
  size_t mSize;
  T* mBuffer;
};

#endif // _DUMMY_VECTOR_H_
