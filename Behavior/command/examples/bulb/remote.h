#ifndef _REMOTE_H_
#define _REMOTE_H_
#include "command.h"
#include <memory>
class Remote {
public:
  void submit(std::shared_ptr<Command> command);
};
#endif // _REMOTE_H_
