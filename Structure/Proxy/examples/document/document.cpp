#include "document.h"

Document::Document() {
  std::cout << "Document() is called!!!" << std::endl;
  initProxy();
}

Document::~Document() {
  std::cout << "~Document() is called" << std::endl;
}

void Document::open(int pageNumber) {
  _proxy.displayContent(pageNumber);
}

void Document::initProxy() {}

void Document::chageToPage(int pageNumber) {
  _proxy.displayContent(pageNumber);
}
