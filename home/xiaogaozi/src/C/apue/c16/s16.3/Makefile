CC = gcc
CFLAGS = -Wall -g
OBJECT = ../../error/err.o

all: f16.8

f16.8: $(OBJECT) f16.8.o
	$(CC) $(CFLAGS) -o f16.8 $(OBJECT) f16.8.o

f16.8.o: f16.8.c
	$(CC) $(CFLAGS) -c f16.8.c

err.o: ../../error/err.c
	$(CC) $(CFLAGS) -c ../../error/err.c

clean:
	rm -f $(OBJECT) f16.8.o f16.8
