#ifndef PRINTER_H
#define PRINTER_H

#include <string>

class Printer
{
protected:
	Printer() =default ;
public:
	Printer(const Printer &) = delete ;
	Printer & operator=(const Printer &) = delete ;
	virtual ~Printer()=default ;
	virtual void Print(const std::string &data)=0 ;
};
#endif
