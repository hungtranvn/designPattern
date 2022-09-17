#include "characterC.h"
#include <iostream>
CharacterA::CharacterC() {
  symbol_ = 'C';
  width_ = 150;
  height_ = 100;
  ascent_ = 75;
  descent_ = 0;
  pointSize_ = 0;
}

void CharacterC::Display(int pointSize) {
  pointSize_ = pointSize;
  std::cout << symbol_ << "(pointsize " << pointSize_ << " )" << endl;
}
