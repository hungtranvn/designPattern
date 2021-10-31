CXXFLAGS += -g -Wall -std=c++17

NAME = car
TARGET = $(NAME).exe

OBJECTS = main.o redcolor.o bluecolor.o modelA.o modelB.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
    
clean:
	-rm -f *.o $(TARGET)
