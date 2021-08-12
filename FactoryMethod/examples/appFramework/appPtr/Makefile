CXXFLAGS += -g -Wall -std=c++17

NAME = app
TARGET = $(NAME).exe

OBJECTS = main.o Application.o TextDocument.o TextApplication.o SpreadSheetDocument.o SpreadSheetApplication.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
    
clean:
	-rm -f *.o $(TARGET)
