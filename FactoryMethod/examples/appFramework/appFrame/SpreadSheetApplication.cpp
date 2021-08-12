#include "SpreadSheetApplication.h"
#include "SpreadSheetDocument.h"

Document* SpreadSheetApplication::Create() {
	return new SpreadSheetDocument{};
}
