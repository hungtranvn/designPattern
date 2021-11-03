CXXFLAGS += -g -Wall -std=c++17

NAME = tree
TARGET = $(NAME).exe

OBJECTS = main.o component.o leaf.o composite.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
    
clean:
	-rm -f *.o $(TARGET)
