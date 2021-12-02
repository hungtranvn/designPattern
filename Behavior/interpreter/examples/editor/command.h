#ifndef _COMMAND_H_
#define _COMMAND_H_
class Command {
protected:
  Application app;
  Editor editor;
public:
  Command(Application app, Editor editor);
  void saveBackup();
  void undo();
  void execute() = 0;
};
#endif // _COMMAND_H_
