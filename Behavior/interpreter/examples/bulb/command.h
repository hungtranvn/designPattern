#ifndef _COMMAND_H_
#define _COMMAND_H_
class Command {
public:
  virtual void execute(void) = 0;
  virtual void undo(void) = 0;
  virtual void redo(void) = 0;
};
#endif // _COMAND_H_
