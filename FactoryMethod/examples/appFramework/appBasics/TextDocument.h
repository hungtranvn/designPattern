#ifndef TEXT_DOCUMENT_H
#define TEXT_DOCUMENT_H
#include "Document.h"
class TextDocument : public Document {
public:
	void Write() override;
	void Read() override;
};
#endif
