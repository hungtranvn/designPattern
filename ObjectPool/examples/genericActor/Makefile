CXXFLAGS += -g -Wall -std=c++17

NAME = pool
TARGET = $(NAME).exe

OBJECTS = main.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
    
clean:
	-rm -f *.o $(TARGET)
