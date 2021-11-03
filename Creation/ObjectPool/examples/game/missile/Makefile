CXXFLAGS += -g -Wall -std=c++17

NAME = missile
TARGET = $(NAME).exe

OBJECTS = main.o Missile.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
    
clean:
	-rm -f *.o $(TARGET)
