CC = g++
CXXFLAGS = -g -Wall -std=c++17

NAME = clock
TARGET = $(NAME).exe

output: main.o Clock.o
	$(CC) $(CXXFLAGS) main.o Clock.o -o $(TARGET)

main.o: main.cpp
	$(CC) $(CXXFLAGS) main.cpp

Clock.o: Clock.cpp Clock.h
	$(CC) $(CXXFLAGS) Clock.cpp

clean:
	-rm -f *.o $(TARGET)
