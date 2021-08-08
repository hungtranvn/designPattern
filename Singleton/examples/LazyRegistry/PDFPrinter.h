#ifndef PDF_PRINTER_H
#define PDF_PRINTER_H
#include "Printer.h"
class PDFPrinter :
    public Printer
{
	PDFPrinter() =default ;
public:
	static PrinterPtr GetInstance() ;
	void Print(const std::string& data) override;
};
#endif
