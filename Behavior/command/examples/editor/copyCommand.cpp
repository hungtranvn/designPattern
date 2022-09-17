#include "copyCommand.h"

bool CopyCommand::execute() {
  saveBackup();
  app.clipboard = editor.getSelection();
  editor.deleteSelection();
  return true;
}

