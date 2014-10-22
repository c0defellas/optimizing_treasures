ARCH := $(shell getconf LONG_BIT)

CC=/usr/bin/gcc
AS=/usr/bin/as
BZERO := bzero_$(ARCH)
CFLAGS=-Wall -g -Ofast -lm

make:
	$(AS) $(BZERO).s -o $(BZERO).o
	$(CC) -o bzero_t bzero_t.c $(BZERO).o $(CFLAGS)

clean:
	rm -f *.o bzero_t

