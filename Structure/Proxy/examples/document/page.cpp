#include "page.h"
#include <iostream>

Page::Page() {
  std::cout << "Page() is called!!!" << std::endl;
}

Page::~Page() {
  std::cout << "~Page() is called!!!" << std::endl;
}

void Page::displayText() {
  std::cout << "Display text." << std::endl;
}

void Page::displayImage() {
  std::cout << "Display an image." << std::endl;
}

void Page::displayVideo() {
  std::cout << "Display an video." << std::endl;
}

void Page::displayEmpty() {
  std::cout << "Nothing to display." << std::endl;
}
