CXXFLAGS += -g -Wall -std=c++17

NAME = liskov2
TARGET = $(NAME).exe

OBJECTS = $(NAME).o 

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
    
clean:
	-rm -f *.o $(TARGET)
