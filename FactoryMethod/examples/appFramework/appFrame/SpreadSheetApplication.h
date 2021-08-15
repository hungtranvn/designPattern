#ifndef SPREAD_SHEET_APPPLICATION_H
#define SPREAD_SHEET_APPLICATION_H
#include "Application.h"
class SpreadSheetApplication : public Application {
public:
	Document* Create() override;
};
#endif
