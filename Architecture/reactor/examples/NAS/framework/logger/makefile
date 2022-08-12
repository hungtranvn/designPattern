#made by shlomi ol70
BASE = ./
PROJECT = ../../

INCFL = $(PROJECT)include/
OBJFL = $(PROJECT)bin/obj/
LIBFL = $(PROJECT)bin/lib/

CC = g++
CFLAGS = -std=c++11 -g -pedantic-errors -Wall -Wextra -I $(INCFL)

SRC = $(wildcard *.cpp)

DEPEND = $(patsubst %.cpp,%.d,$(SRC))
OBJS = $(patsubst %.cpp,%.o,$(SRC))
TARGET = $(patsubst %.cpp,%.so,$(SRC))

PI = 0
ifeq ($(PI), 1)
CC = arm-linux-gnueabi-g++
endif

.PHONY: ALL
ALL:
	make CHECKS_D_FILES CHECKS_OBJ_FILES CHECKS_TARGET_FILES

%.d: %.cpp
	@set -e; rm -f $@; \
	$(CC) -M $(CFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

%.o: %.cpp %.d
	$(CC) $(CFLAGS) $< -fPIC -c

$(TARGET): $(OBJS)
	$(CC) -shared -fPIC $^ -o $@

.PHONY: CHECKS_D_FILES
CHECKS_D_FILES:
	echo CHECKS D FILES
	make $(DEPEND)

.PHONY: CHECKS_OBJ_FILES
CHECKS_OBJ_FILES:
	echo CHECKS OUT FILES
	make $(OBJS)

.PHONY: CHECKS_TARGET_FILES
CHECKS_TARGET_FILES:
	-mv $(LIBFL)$(TARGET) $(BASE)
	echo CHECKS SO FILES
	make $(TARGET)
	mv $(BASE)$(TARGET) $(LIBFL)

.PHONY: CLEAN
CLEAN:
	-rm *.d
	-rm *.o