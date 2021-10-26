#ifndef DIRECTOR_H
#define DIRECTOR_H
#include <windows.h>
class FileBuilder;
class Director {
	FileBuilder *m_pBuilder;
public:
	Director(FileBuilder* builder);
	void Create(const char *pFileName, DWORD desiredAccess);
};
#endif
