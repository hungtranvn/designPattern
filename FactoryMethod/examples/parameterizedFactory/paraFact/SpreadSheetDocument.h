#ifndef SPREAD_SHEET_DOCUMENT_H
#define SPREAD_SHEET_DOCUMENT_H
#include "Document.h"
class SpreadSheetDocument : public Document {
public:
	void Write() override;
	void Read() override;
};
#endif
