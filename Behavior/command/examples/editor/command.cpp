#include "command.h"

Command::Command(Application app, Editor editor) {
  this.app = app;
  this.editor = editor;
}

void Command::saveBackup() {
  backup = editor.text;
}

void Command::undo() {
  editor.text = backup;
}
