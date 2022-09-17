CC		= g++
CFLAGS	= -Wall -g -O
INCLUDE =
LIBS	= 
OBJS 	= server.o initiation_Dispatcher.o logging_Acceptor.o logging_Handler.o net.o
DEL 	= client.o server.o initiation_Dispatcher.o logging_Acceptor.o logging_Handler.o net.o
SOURCE	=	$(OBJS:.o=.cpp)

TARGET 	= server.out client.out clean

all : $(TARGET)
.PHONY: all clean execute

server.out : $(OBJS)
	$(CC) -o $@ $^

client.out : 
	gcc -o client.out client.cpp

%.o : %.cpp
		$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDES)

%.d : %.cpp
		@set -e; rm -f $@; $(CC) -MM $(CFLAGS) $(INCLUDES) $< > $@.$$$$; \
		sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@;  \
		rm -f $@.$$$$ 


.PHONY: clean

clean :
	@echo Borrando ficheros.o ...
	rm *.o
	@echo permisos de ejecución client.out y server.out ...
	chmod +x client.out 
	chmod +x server.out
