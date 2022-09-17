#include "characterA.h"
#include <iostream>
CharacterA::CharacterA() {
  symbol_ = 'A';
  width_ = 120;
  height_ = 100;
  ascent_ = 70;
  descent_ = 0;
  pointSize_ = 0;
}

void CharacterA::Display(int pointSize) {
  pointSize_ = pointSize;
  std::cout << symbol_ << "(pointsize " << pointSize_ << " )" << endl;
}
