BASE = ./
PROJECT = ../../

INCFL = $(PROJECT)include/
OBJFL = $(PROJECT)bin/obj/
LIBFL = $(PROJECT)bin/lib/

CC = g++
CFLAGS = -std=c++11 -g -pedantic-errors -Wall -Wextra -I $(INCFL)

SRC = $(wildcard *.cpp)

DEPEND = $(patsubst %.cpp, %.d, $(SRC))
OBJS = $(patsubst %.cpp, %.o, $(SRC))
TARGET = $(patsubst %.cpp, %.so, $(SRC))

PI = 0
ifeq ($(PI), 1)
CC = arm-linux-gnueabi-g++
endif

.PHONY: ALL
ALL:
	make TOUCH_TEMPS MOVE_TO_BASE CHECK_COMPILE MOVE_FROM_BASE REMOVE_TEMPS

%.d: %.cpp
	@set -e; rm -f $@; \
	$(CC) -M $(CFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

%.o: %.cpp %.d
	$(CC) $(CFLAGS) $< -shared -fPIC -c

%.so: $(OBJS)
	$(CC) -shared -fPIC $^ -o $@

.PHONY: TOUCH_TEMPS
TOUCH_TEMPS:
	touch $(LIBFL)tempytemp.so

.PHONY: MOVE_TO_BASE
MOVE_TO_BASE:
	mv $(LIBFL)*.so $(BASE)

.PHONY: CHECK_COMPILE
CHECK_COMPILE:
	echo CHECKS D FILES
	make $(DEPEND)
	echo CHECKS O FILES
	make $(OBJS)
	echo CHECKS SO FILES
	make $(TARGET)

.PHONY: MOVE_FROM_BASE
MOVE_FROM_BASE:
	mv $(BASE)*.so $(LIBFL)

.PHONY: REMOVE_TEMPS
REMOVE_TEMPS:
	rm $(LIBFL)tempytemp.so

.PHONY: CLEAN
CLEAN:
	rm *.d
	rm *.o