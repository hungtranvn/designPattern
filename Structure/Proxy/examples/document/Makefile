CXXFLAGS += -g -Wall -std=c++17

NAME = proxy
TARGET = $(NAME).exe

OBJECTS = main.o proxy.o realSubject.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
    
clean:
	-rm -f *.o $(TARGET)
