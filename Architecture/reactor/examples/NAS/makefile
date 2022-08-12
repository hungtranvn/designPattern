BASE = ./

LIBFL = $(BASE)bin/lib/
OBJFL = $(BASE)bin/obj/
EXEFL = $(BASE)bin/exe/

FRAMEWORKFD = $(BASE)framework/

PI = 0

.PHONY: ALL
ALL:
	make MAKE_OTHER

.PHONY: MAKE_OTHER
MAKE_OTHER:
	$(MAKE) -C $(FRAMEWORKFD) PI=$(PI)

.PHONY: CLEAN
CLEAN:
	-rm $(OBJFL)*.o
	-rm $(LIBFL)*.so
	-rm $(EXEFL)*.out
	-$(MAKE) -C $(FRAMEWORKFD) CLEAN