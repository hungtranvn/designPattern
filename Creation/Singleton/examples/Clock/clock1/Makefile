CXXFLAGS += -g -Wall -std=c++17

NAME = clock
TARGET = $(NAME).exe

OBJECTS = main.o clock.o 

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
    
clean:
	-rm -f *.o $(TARGET)
