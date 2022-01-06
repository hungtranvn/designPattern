#include "pageProxy.h"
#include <iostream>

PageProxy::PageProxy() {
  std::cout << "PageProxy() is called!!!" << std::endl;
  _page = NULL;
}

PageProxy::~PageProxy() {
  std::cout << "~PageProxy() is called!!!" << std::endl;
}

std::shared_ptr<Page> PageProxy::getPage() {
  if(NULL == _page) {
    _page = std::make_shared<Page>();
  }
  
  return _page;
}

void PageProxy::setCurrentPage(int currentPage) {
  _currentPage = currentPage;
}

const int PageProxy::getCurrentPage() const {
  return _currentPage;
}

void PageProxy::displayContent(int pageNumber) {
  setCurrentPage(pageNumber);
  std::cout << std::endl << "On page \"" << getCurrentPage() << "\":" \
    << std::endl;
  switch (pageNumber) {
    case 1:
      getPage()->displayText();
      break;
    case 24:
      getPage()->displayText();
      getPage()->displayImage();
      break;
    case 37:
      getPage()->displayText();
      getPage()->displayImage();
      getPage()->displayVideo();
      break;
    default:
      getPage()->displayEmpty();
      break;
  }

  std::cout << std::endl;
}

void PageProxy::displayText() {}

void PageProxy::displayImage() {}

void PageProxy::displayVideo() {}

void PageProxy::displayEmpty() {}
