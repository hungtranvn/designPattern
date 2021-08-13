#ifndef DOCUMENT_FACTORY_H
#define DOCUMENT_FACTORY_H
#include <string>
#include "Document.h"
class DocumentFactory {
public:
	static DocumentPtr Create(const std::string &type) ;
};
#endif
