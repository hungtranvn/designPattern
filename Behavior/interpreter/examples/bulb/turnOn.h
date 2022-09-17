#ifndef _TURN_ON_H_
#define _TURN_ON_H_
#include <memory>
#include "command.h"
#include "bulb.h"
class TurnOn : public Command {
public:
  TurnOn(std::shared_ptr<Bulb> bulb);
  void execute(void);
  void undo(void);
  void redo(void);
private:
  std::shared_ptr<Bulb> bulb_;
};
#endif // _TURN_ON_H_
