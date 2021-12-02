#include "remote.h"

void Remote::submit(std::shared_ptr<Command> command) {
  command->execute();
}
