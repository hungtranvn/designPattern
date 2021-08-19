CXXFLAGS += -g -Wall -std=c++17

NAME = pointFac
TARGET = $(NAME).exe

OBJECTS = main.o PointCartesian.o PointPolar.o \
					Creator.o PolarCreator.o CartesianCreator.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
    
clean:
	-rm -f *.o $(TARGET)
