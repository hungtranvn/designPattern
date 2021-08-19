CXXFLAGS += -g -Wall -std=c++17

NAME = point1
TARGET = $(NAME).exe

OBJECTS = main.o Point.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
    
clean:
	-rm -f *.o $(TARGET)
