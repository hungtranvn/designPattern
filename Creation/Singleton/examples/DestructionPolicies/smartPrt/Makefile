CXXFLAGS += -g -Wall -std=c++17

NAME = smartPtr
TARGET = $(NAME).exe

OBJECTS = main.o Logger.o 

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
    
clean:
	-rm -f *.o $(TARGET)
