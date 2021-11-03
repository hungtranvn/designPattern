#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>
#include <type_traits>

struct Person {
  Person();
  ~Person();
  void greet();
private:
  static constexprsize_t m_size = 1024;
  using pimpl_storage_t = aligned_storage<m_size, alignment_of_v <max_align_t>>::type;
  
  std::string  m_name;
  pimpl_storage_t m_impl;
}

#endif // _PERSON_H_
