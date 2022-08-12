SYS			:=	$(shell gcc -dumpmachine)
CC			=	g++
#CC			=	clang++

TARGET		=	test
SOURCES		= main.cpp \

######################################## include
INCLUDE	=  -I../../
LDFLAGS += -L../../ -lreactor

######################################## default
LDFLAGS += -lrt -lpthread -lcrypto

CPPFLAGS += -g -D_REENTRANT
CPPFLAGS += -O2 -std=c++11 -Wall -Wextra -Wfloat-equal -m64

OBJECTS		:=	$(SOURCES:.cpp=.o)

all: $(OBJECTS)
	rm -rf core.*
#	ar rcv $(TARGET) $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(CPPFLAGS) $(LDFLAGS)

clean:
	rm -rf $(TARGET) $(OBJECTS)

install: all
	rm -rf $(INSTALL_DIR)/$(TARGET).bak
	mv $(INSTALL_DIR)/$(TARGET) $(INSTALL_DIR)/$(TARGET).bak
	cp $(TARGET) $(INSTALL_DIR)

.c.o: $(.cpp.o)
.cpp.o:
	$(CC) $(INCLUDE) $(CPPFLAGS) -c $< -o $@

