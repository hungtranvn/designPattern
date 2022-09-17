#ifndef _CPU_H_
#define _CPU_H_
#include <string>

class CPU {
public:
  void freeze();
  void jump(long position);
  void execute();
};
#endif // _CPU_H_
