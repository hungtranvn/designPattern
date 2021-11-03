#ifndef APPLICATION_H
#define APPLICATION_H
#include <memory>
#include "Document.h"
class Application {
	DocumentPtr m_pDocument ;
public:
	void New();
	void Open();
	void Save();
};
#endif
