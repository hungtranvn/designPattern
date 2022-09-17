#ifndef _ITERATOR_H_
#define _ITERATOR_H_
class Iterator {
public:
  virtual ~Iterator() = default;
  virtual void first() = 0;
  virtual void next() = 0;
  virtual bool isDone() = 0;
  virtual int currentItem() = 0;
};
#endif //_ITERATOR_H_
