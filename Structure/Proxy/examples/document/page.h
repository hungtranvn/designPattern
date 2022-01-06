#ifndef _PAGE_H_
#define _PAGE_H_

#include "iPage.h"

class Page : public IPage {
public:
  Page();
  ~Page();

  void displayText() override;
  void displayImage() override;
  void displayVideo() override;
  void displayEmpty() override;
};
#endif // _PAGE_H_
