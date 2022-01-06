#ifndef _PAGE_PROXY_H_
#define _PAGE_PROXY_H_

#include "iPage.h"
#include "page.h"
#include <memory>

class PageProxy : public IPage {
public:
  PageProxy();
  ~PageProxy();

  void displayText() override;
  void displayImage() override;
  void displayVideo() override;
  void displayEmpty() override;

  void setCurrentPage(int currentPage);
  const int getCurrentPage() const;
  std::shared_ptr<Page> getPage();
  void displayContent(int pageNumber);
private:
  int _currentPage;
  std::shared_ptr<Page> _page;
};

#endif // _PAGE_PROXY_H
