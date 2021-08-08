#ifndef LOCAL_PRINTER_H
#define LOCAL_PRINTER_H
#include <string>
class LocalPrinter {
	static LocalPrinter m_Instance;
	LocalPrinter() = default;
public:
  LocalPrinter(const LocalPrinter&) = delete;
	LocalPrinter& operator=(const LocalPrinter&) = delete;
  static  LocalPrinter & GetInstance();
	void Print(const std::string &data);
};
#endif
