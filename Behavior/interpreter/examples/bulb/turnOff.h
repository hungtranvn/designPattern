#ifndef _TURN_OFF_H_
#define _TURN_OFF_H_
#include "command.h"
#include "bulb.h"
#include <memory>
class TurnOff : public Command {
public:
  TurnOff(std::shared_ptr <Bulb> bulb);
  void execute(void);
  void undo(void);
  void redo(void);
private:
  std::shared_ptr<Bulb> bulb_;
};
#endif // _TURN_OFF_H_
