CXXFLAGS += -g -Wall -std=c++17

NAME = basic
TARGET = $(NAME).exe

OBJECTS = main.o Singleton.o 

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
    
clean:
	-rm -f *.o $(TARGET)
