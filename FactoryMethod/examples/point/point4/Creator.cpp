#include "Creator.h"
void Creator::operation() {
  m_pPoint = create();
  m_pPoint->anOperation();
}
