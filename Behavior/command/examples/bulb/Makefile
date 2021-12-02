CXXFLAGS += -g -Wall -std=c++17

NAME = command
TARGET = $(NAME).exe

OBJECTS = main.o remote.o bulb.o turnOn.o turnOff.o 

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
    
clean:
	-rm -f *.o $(TARGET)
