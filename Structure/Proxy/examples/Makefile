CXXFLAGS += -g -Wall -std=c++17

NAME = facade
TARGET = $(NAME).exe

OBJECTS = main.o cpu.o hardDriver.o memory.o computerFacade.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
    
clean:
	-rm -f *.o $(TARGET)
