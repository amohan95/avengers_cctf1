CC=gcc
CFLAGS=-O3
IDIR=lib
ODIR=bin

all: spoof test

spoof: spoof.o init.o
	$(CC) $(CFLAGS) $(LIBS) -I$(IDIR) -o $(ODIR)/$@ $(ODIR)/spoof.o $(ODIR)/init.o

test: dns_test

dns_test: dns_test.c
	$(CC) $(CFLAGS) $(LIBS) -I$(IDIR) -o $(ODIR)/$@ $<

spoof.o: spoof.c
	$(CC) -c $(CFLAGS) -I$(IDIR) -o $(ODIR)/$@ $<

init.o: init.c
	$(CC) -c $(CFLAGS) -I$(IDIR) -o $(ODIR)/$@ $<

.PHONY: clean

clean:
	rm -f $(ODIR)/*
