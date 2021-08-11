CXXFLAGS += -g -Wall -std=c++17

NAME = factory
TARGET = $(NAME).exe

OBJECTS = main.o ConcreteCreator.o Creator.o ConcreteProduct.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
    
clean:
	-rm -f *.o $(TARGET)
