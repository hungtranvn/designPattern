#include "characterE.h"
#include <iostream>
CharacterA::CharacterE() {
  symbol_ = 'E';
  width_ = 110;
  height_ = 100;
  ascent_ = 80;
  descent_ = 0;
  pointSize_ = 0;
}

void CharacterE::Display(int pointSize) {
  pointSize_ = pointSize;
  std::cout << symbol_ << "(pointsize " << pointSize_ << " )" << endl;
}
