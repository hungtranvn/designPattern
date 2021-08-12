#include "SpreadSheetApplication.h"
#include "SpreadSheetDocument.h"

DocumentPtr SpreadSheetApplication::Create() {
	return std::make_unique<SpreadSheetDocument>();
}
