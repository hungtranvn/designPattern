CXXFLAGS += -g -Wall -std=c++17

NAME = clock
TARGET = $(NAME).exe

output: main.o Clock.o
	$(CXX) $(CXXFLAGS) main.o Clock.o -o $(TARGET)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

Clock.o: Clock.cpp Clock.h
	$(CXX) $(CXXFLAGS) Clock.cpp

clean:
	-rm -f *.o $(TARGET)
