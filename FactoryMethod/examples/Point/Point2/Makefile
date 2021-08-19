CXXFLAGS += -g -Wall -std=c++17

NAME = point
TARGET = $(NAME).exe

OBJECTS = main.o Point2.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
    
clean:
	-rm -f *.o $(TARGET)
