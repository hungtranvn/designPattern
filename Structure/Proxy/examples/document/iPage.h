#ifndef _I_PAGE_H_
#define _I_PAGE_H_
/*
 * Page class: an interface
 * */
class IPage {
public:
  virtual ~IPage() = default;
  virtual void displayText() = 0;
  virtual void displayImage() = 0;
  virtual void displayVideo() = 0;
  virtual void displayEmpty() = 0;
};
#endif // _I_PAGE_H_
