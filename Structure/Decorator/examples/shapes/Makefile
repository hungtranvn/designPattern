CXXFLAGS += -g -Wall -std=c++17

NAME = shape
TARGET = $(NAME).exe

OBJECTS = main.o circle.o coloredShape.o transparentShape.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
    
clean:
	-rm -f *.o $(TARGET)
