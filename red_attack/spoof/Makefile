CC=gcc
CFLAGS=-std=c99 -Ofast -Wpedantic
IDIR=lib
ODIR=bin

all: spoof

spoof: spoof.o init.o
	$(CC) $(CFLAGS) $(LIBS) -I$(IDIR) -o $(ODIR)/$@ $(ODIR)/spoof.o $(ODIR)/init.o

spoof.o: spoof.c
	$(CC) -c $(CFLAGS) -I$(IDIR) -o $(ODIR)/$@ $<

init.o: init.c
	$(CC) -c $(CFLAGS) -I$(IDIR) -o $(ODIR)/$@ $<

.PHONY: clean

clean:
	rm -f $(ODIR)/*
