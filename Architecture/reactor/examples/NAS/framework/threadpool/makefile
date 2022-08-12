#made by shlomi ol70
BASE = ./
PROJECT = ../../

INCFL = $(PROJECT)include/
OBJFL = $(PROJECT)bin/obj/
EXEFL = $(PROJECT)bin/exe/

SHARED_LIB = -lpthread -ldl ~/git/projects/bin/lib/*.so

CC = g++
CFLAGS = -std=c++11 -g -pedantic-errors -Wall -Wextra -I $(INCFL)

SRC = $(wildcard *.hpp)

TEST_FILE = $(patsubst %.hpp, %_test.cpp, $(SRC))

DEPEND = $(patsubst %.hpp,%.d,$(SRC)) $(patsubst %.cpp,%.d,$(TEST_FILE))
OBJS = $(patsubst %.hpp,%.o,$(SRC))
TARGET = $(patsubst %.cpp,%.out,$(TEST_FILE))

OBJS_IN_DEST = $(patsubst %.o,$(OBJFL)%.o,$(OBJS))
TARGET_IN_DEST = $(patsubst %.out,$(EXEFL)%.out,$(TARGET))

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

%.o: %.cpp %.d $(SRC)
	$(CC) $(CFLAGS) $< -c

$(TARGET): $(SRC) *.cpp *.d
	$(CC) $(CFLAGS) $(TEST_FILE) $(OBJFL)*.o $(SHARED_LIB) -o $(TARGET)

.PHONY: CHECKS_D_FILES
CHECKS_D_FILES:
	echo CHECKS D FILES
	make $(DEPEND)

.PHONY: CHECKS_OBJ_FILES
CHECKS_OBJ_FILES:
	echo CHECKS O FILES
	-mv $(OBJS_IN_DEST) $(BASE)
	make $(OBJS)
	mv $(OBJS) $(OBJFL)

.PHONY: CHECKS_TARGET_FILES
CHECKS_TARGET_FILES:
	echo CHECKS TARGET FILES
	-mv $(TARGET_IN_DEST) $(BASE)
	make $(TARGET)
	mv $(TARGET) $(EXEFL)

.PHONY: CLEAN
CLEAN:
	-rm *.d
	-rm *.o