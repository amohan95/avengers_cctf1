CC=gcc
CFLAGS=-std=c99 -Ofast -Wall
IDIR=lib
ODIR=bin

all: spoof

spoof: spoof.o
	$(CC) $(CFLAGS) $(LIBS) -I$(IDIR) -o $(ODIR)/$@ $(ODIR)/spoof.o 

spoof.o: spoof.c
	$(CC) -c $(CFLAGS) -I$(IDIR) -o $(ODIR)/$@ $<

.PHONY: clean

clean:
	rm -f $(ODIR)/*
