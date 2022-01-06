#ifndef _DOCUMENT_H_
#define _DOCUMENT_H_

#include <memory>
#include "pageProxy.h"

class Document {
public:
  Document();
  ~Document();
  
  void open(int page = 1);
  void initProxy();
  void changeToPage(int pageNumber);
private:
  PageProxy _proxy;
};

#endif // _DOCUMENT_H_
