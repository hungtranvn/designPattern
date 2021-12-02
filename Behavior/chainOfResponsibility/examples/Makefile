CXXFLAGS += -g -Wall -std=c++17

NAME = chain
TARGET = $(NAME).exe

OBJECTS = main.o handler.o concreteHandler1.o concreteHandler2.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
    
clean:
	-rm -f *.o $(TARGET)
