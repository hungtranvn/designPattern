#include "TextApplication.h"
#include "TextDocument.h"
Document* TextApplication::Create() {
	return new TextDocument{};
}
