SYS		:=	$(shell gcc -dumpmachine)
CC		=	g++
#CC		=	clang++

TARGET		=	libreactor.a
SOURCES		=	acceptor/Acceptor.cpp \
      			acceptor/AcceptorThread.cpp \
      			reactor/Reactor.cpp \
      			reactor/Reactors.cpp \
      			reactor/ReactorHandler.cpp

INSTALL_DIR	=	./
INCLUDE		=	-I./
CPPFLAGS	+=	-g
CPPFLAGS	+=	-D_REENTRANT
CPPFLAGS	+=	-O2 -std=c++11 -Wall -Wextra -Wfloat-equal -m64

OBJECTS		:=	$(SOURCES:.cpp=.o)

all: $(OBJECTS)
	rm -rf core.*
	ar rcv $(TARGET) $(OBJECTS)

clean:
	rm -rf $(TARGET) $(OBJECTS)

install: all
#	cp $(TARGET) $(INSTALL_DIR)

.c.o: $(.cpp.o)
.cpp.o:
	$(CC) $(INCLUDE) $(CPPFLAGS) -c $< -o $@
