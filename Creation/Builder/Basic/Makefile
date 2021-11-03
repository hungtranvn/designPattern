CXXFLAGS += -g -Wall -std=c++17

NAME = builder
TARGET = $(NAME).exe

OBJECTS = main.o Product.o Director.o ConcreteBuilder.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
    
clean:
	-rm -f *.o $(TARGET)
