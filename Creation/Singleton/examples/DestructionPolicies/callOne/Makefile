CXXFLAGS += -g -Wall -std=c++17

NAME = callone
TARGET = $(NAME).exe

output: main.o Logger.o
	$(CXX) -pthread main.o Logger.o -o $(TARGET)

main.o: main.cpp
	$(CXX) -pthread -c main.cpp

Logger.o: Logger.cpp Logger.h
	$(CXX) -pthread -c Logger.cpp

clean:
	-rm -f *.o $(TARGET)
