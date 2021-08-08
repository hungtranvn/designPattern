#ifndef PDF_PRINTER_H
#define PDF_PRINTER_H

#include "Printer.h"
class PDFPrinter : public Printer
{
	static PDFPrinter m_Instance  ;
	PDFPrinter() ;
public:
	void Print(const std::string& data) override;
};
#endif
