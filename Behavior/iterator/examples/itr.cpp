#include <iterator>
#include <typeinfo>
#include <iostream>
#include <string>

class BaseItr {
public:
  class iterator : public std::iterator<std::input_iterator_tag, int> {
  public:
    iterator() : _in(NULL) {}
    inline iterator(const iterator& org) : _in(org._in) {}
    
    virtual inline int operator * () {
      return _in->operator*();
    }
    
    virtual inline iterator& operator++() {
      (*_in)++;
      return *this;
    }

    virtual inline iterator& operator++(int unused) {
      (*_in)++;
      return *this;
    }
    
    virtual inline bool operator==(const iterator& other) {
      return *(*_in) == *(*(other._in));
    }

    virtual inline bool operator!=(const iterator& other) {
      return *(*_in) != *(*(other._in));
    }

    static inline iterator New(iterator *in) {
      return iterator *_in;
    }
  private:
    iterator(iterator *in) : _in(in) {}
    iterator *_in;
  };

  virtual iterator begin() = 0;
  virtual iterator end() = 0;
};

class Itr : public BaseItr {
private:
  class iterator : public BaseItr::iterator{
  public:
    iterator(int val) : _val(val), BaseItr::iterator() {}
    int operator *() {return _val;}
    inline iterator& operator++() {
      ++_val;
      return *this;
    }

    inline iterator& operator++(int unused) {
      _val++;
      return *this;
    }

  private:
    int _val;
  };

  BaseItr::iterator _begin;
  BaseItr::iterator _end;

public:
  inline Itr(int start, int end) {
    _begin = BaseItr::iterator::New(new iterator(start));
    _end = BaseItr::iterator::New(new iterator(end));
  }

  BaseItr::iterator begin() {return _begin;}
  BaseItr::iterator end() {return _end;}
};

int main() {
  BaseItr *base = new Itr(10, 100);
  BaseItr::iterator itr = base->begin();
  BaseItr::iterator end = base->end();

  std::copy(itr, end, std::ostream_iterator<int>(std::cout, ","));
  std::cout << std::endl;

  return 0;
}
