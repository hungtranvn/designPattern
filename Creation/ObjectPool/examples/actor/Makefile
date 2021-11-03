CXXFLAGS += -g -Wall -std=c++17

NAME = actor
TARGET = $(NAME).exe

OBJECTS = main.o ActorPool.o Missile.o Alien.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
    
clean:
	-rm -f *.o $(TARGET)
