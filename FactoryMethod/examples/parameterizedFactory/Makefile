CXXFLAGS += -g -Wall -std=c++17

NAME = app
TARGET = $(NAME).exe

OBJECTS = main.o Application.o DocumentFactory.o \
					TextDocument.o SpreadSheetDocument.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
    
clean:
	-rm -f *.o $(TARGET)
