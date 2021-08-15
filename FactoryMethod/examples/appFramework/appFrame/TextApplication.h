#ifndef TEXT_APPLICATION_H
#define TEXT_APPLICATION_H
#include "Application.h"
class TextApplication : public Application {
public:
	Document* Create() override;
};
#endif
