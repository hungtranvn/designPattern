#ifndef APPLICATION_H
#define APPLICATION_H
#include <memory>
#include "Document.h"
//class Document;
using DocumentPtr = std::unique_ptr<Document>;
class Application {
	DocumentPtr m_pDocument;
public:
	void New();
	void Open();
	void Save();
	virtual DocumentPtr Create(){return nullptr;}
};
#endif
