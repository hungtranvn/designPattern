CC = g++
CXXFLAGS = -g -Wall -std=c++17

NAME = clock
TARGET = $(NAME).exe

output: main.o clock.o
	$(CC) $(CXXFLAGS) main.o clock.o -o $(TARGET)

main.o: main.cpp
	$(CC) $(CXXFLAGS) main.cpp

Clock.o: clock.cpp clock.h
	$(CC) $(CXXFLAGS) clock.cpp

clean:
	-rm -f *.o $(TARGET)
