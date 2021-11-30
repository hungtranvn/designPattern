#include "characterB.h"
#include <iostream>
CharacterA::CharacterB() {
  symbol_ = 'B';
  width_ = 145;
  height_ = 100;
  ascent_ = 78;
  descent_ = 0;
  pointSize_ = 0;
}

void CharacterB::Display(int pointSize) {
  pointSize_ = pointSize;
  std::cout << symbol_ << "(pointsize " << pointSize_ << " )" << endl;
}
