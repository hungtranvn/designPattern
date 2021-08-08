CXXFLAGS += -g -Wall -std=c++17

NAME1 = LocalPrinter
NAME2 = Printer
TARGET = $(NAME1).exe

OBJECTS = main.o $(NAME1).o $(NAME2).o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
    
clean:
	-rm -f *.o $(TARGET)
