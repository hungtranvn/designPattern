#include "characterD.h"
#include <iostream>
CharacterA::CharacterD() {
  symbol_ = 'D';
  width_ = 130;
  height_ = 100;
  ascent_ = 74;
  descent_ = 0;
  pointSize_ = 0;
}

void CharacterD::Display(int pointSize) {
  pointSize_ = pointSize;
  std::cout << symbol_ << "(pointsize " << pointSize_ << " )" << endl;
}
