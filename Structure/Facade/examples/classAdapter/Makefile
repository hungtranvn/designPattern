CXXFLAGS += -g -Wall -std=c++17

NAME = adapter
TARGET = $(NAME).exe

OBJECTS = main.o adapter.o rectangle.o square.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
    
clean:
	-rm -f *.o $(TARGET)
