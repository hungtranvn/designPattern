#include <memory>
#include <iostream>
#include "pageProxy.h"
#include "document.h"

int main() {
  Document doc;

  doc.open();
  doc.changeToPage(4);
  doc.changeToPage(15);
  doc.changeToPage(24);
  doc.changeToPage(37);
  doc.changeToPage(59);

  return 0;
}
