#Programs variables
CC = gcc
AR = ar

#Flags variables
CFLAGS = -g -Wall
DFLAGS = -shared
SFLAGS = rcs
F = -fPIC

#File variables
MAIN = main.c
LOOP = advancedClassificationLoop.c
REC = advancedClassificationRecursion.c
BASE = basicClassification.c
ALLSRC = advancedClassificationLoop.c advancedClassificationRecursion.c basicClassification.c
HEAD = NumClass.h
LIBSLOOP = libclassloops.a
LIBDLOOP = libclassloops.so
LIBSREC = libclassrec.a
LIBDREC = libclassrec.so

.PHONY: loops recursives recursived loopd all clean

all: mains maindloop maindrec loops recursives recursived loopd

#Build libraries

loops: $(LIBSLOOP)
recursives: $(LIBSREC)
recursived: $(LIBDREC)
loopd: $(LIBDLOOP)

#Main program with static recursive library
mains: $(MAIN:.c=.o) $(LIBSREC)
	$(CC) $(CFLAGS) $< ./$(LIBSREC) -o $@

#Main program with dynamic loop library
maindloop: $(MAIN:.c=.o) $(LIBDLOOP)
	$(CC) $(CFLAGS) $< ./$(LIBDLOOP) -o $@

#Main program with dynamic recursive library
maindrec: $(MAIN:.c=.o) $(LIBDREC)
	$(CC) $(CFLAGS) $< ./$(LIBDREC) -o $@

#Building The Libraries
$(LIBSLOOP): $(LOOP:.c=.o) $(BASE:.c=.o)
	$(AR) $(SFLAGS) $@ $^

$(LIBSREC): $(REC:.c=.o) $(BASE:.c=.o)
	$(AR) $(SFLAGS) $@ $^

$(LIBDREC): $(REC:.c=.o) $(BASE:.c=.o)
	$(CC) $(DFLAGS) $(CFLAGS) $^ -o $@

$(LIBDLOOP): $(LOOP:.c=.o) $(BASE:.c=.o)
	$(CC) $(DFLAGS) $(CFLAGS) $^ -o $@

#Building object files
$(MAIN:.c=.o): $(MAIN) $(HEAD)
	$(CC) $(CFLAGS) -c $<

$(ALLSRC:.c=.o): $(ALLSRC) $(HEAD)
	$(CC) $(CFLAGS) $(F) -c $<

#clean all
clean:
	rm -f mains maindloop maindrec *.o *.a .so