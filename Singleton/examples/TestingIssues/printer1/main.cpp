#include "LocalPrinter.h"

void PrintSales() {
	LocalPrinter::GetInstance().Print("Sales data");
}

int main() {
	auto &p = LocalPrinter::GetInstance();
	p.Print("Printing data to local printer");
	PrintSales();
}
