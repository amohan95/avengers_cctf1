CC=gcc
CFLAGS=-std=c99 -O3
IDIR=lib
ODIR=bin

all: test

test: dns_test init_test

dns_test: dns_test.o dns.o
	$(CC) $(CFLAGS) $(LIBS) -I$(IDIR) -o $(ODIR)/$@ $(ODIR)/dns_test.o $(ODIR)/dns.o

init_test: init_test.o init.o
	$(CC) $(CFLAGS) $(LIBS) -I$(IDIR) -o $(ODIR)/$@ $(ODIR)/init_test.o $(ODIR)/init.o

dns_test.o: dns_test.c
	$(CC) -c $(CFLAGS) -I$(IDIR) -o $(ODIR)/$@ $<

init_test.o: init_test.c
	$(CC) -c $(CFLAGS) -I$(IDIR) -o $(ODIR)/$@ $<

spoof.o: spoof.c
	$(CC) -c $(CFLAGS) -I$(IDIR) -o $(ODIR)/$@ $<

dns.o: dns.c
	$(CC) -c $(CFLAGS) -I$(IDIR) -o $(ODIR)/$@ $<

init.o: init.c
	$(CC) -c $(CFLAGS) -I$(IDIR) -o $(ODIR)/$@ $<

.PHONY: clean

clean:
	rm -f $(ODIR)/*
