#include "DocumentFactory.h"
#include "TextDocument.h"
#include "SpreadSheetDocument.h"

DocumentPtr DocumentFactory::Create(const std::string& type) {
	if(type == "text")
		return std::make_unique<TextDocument>();
	else if(type == "spreadsheet")
		return std::make_unique<SpreadSheetDocument>();
	return nullptr ;
}
