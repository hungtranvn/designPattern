CXXFLAGS += -g -Wall -std=c++17

NAME = observer
TARGET = $(NAME).exe

OBJECTS = main.o JobPost.o JobPosting.o JobSeeker.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
    
clean:
	-rm -f *.o $(TARGET)
