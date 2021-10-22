CXXFLAGS += -g -Wall -std=c++17

NAME = printer
TARGET = $(NAME).exe

OBJECTS = main.o LocalPrinter.o PDFPrinter.o PrinterProvider.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
    
clean:
	-rm -f *.o $(TARGET)
