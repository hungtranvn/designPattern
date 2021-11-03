#include "Application.h"
#include "TextApplication.h"
#include "SpreadSheetApplication.h"

int main() {
	SpreadSheetApplication app;
	app.New();
	app.Open();
	app.Save();
}
