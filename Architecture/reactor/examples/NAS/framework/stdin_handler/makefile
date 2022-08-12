#made by shlomi ol70
BASE = ./
PROJECT = ../../

INCFL = $(PROJECT)include/
OBJFL = $(PROJECT)bin/obj/

CC = g++
CFLAGS = -std=c++11 -g -pedantic-errors -Wall -Wextra -I $(INCFL)

SRC = $(wildcard *.cpp)
DEPEND = $(patsubst %.cpp,%.d,$(SRC))
TARGET = $(patsubst %.cpp,%.o,$(SRC))
TARGET_IN_DEST = $(patsubst %.o,$(OBJFL)%.o,$(TARGET))

PI = 0
ifeq ($(PI), 1)
CC = arm-linux-gnueabi-g++
endif

.PHONY: ALL
ALL:
	make CHECKS_D_FILES CHECKS_TARGET_FILES

%.d: %.cpp
	@set -e; rm -f $@; \
	$(CC) -M $(CFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

%.o: %.cpp %.d
	$(CC) $(CFLAGS) $< -c

.PHONY: CHECKS_D_FILES
CHECKS_D_FILES:
	echo CHECKS D FILES
	make $(DEPEND)

.PHONY: CHECKS_TARGET_FILES
CHECKS_TARGET_FILES:
	echo CHECKS TARGET FILES
	-mv $(TARGET_IN_DEST) $(BASE)
	make $(TARGET)
	mv $(TARGET) $(OBJFL)

.PHONY: CLEAN
CLEAN:
	rm *.d