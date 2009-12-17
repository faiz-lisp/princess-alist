CC = gcc
CFLAGS = -Wall -g
OBJECT = ../../error/err.o

all: f15.5 f15.6

f15.5: $(OBJECT) f15.5.o
	$(CC) $(CFLAGS) -o f15.5 $(OBJECT) f15.5.o

f15.5.o: f15.5.c
	$(CC) $(CFLAGS) -c f15.5.c

f15.6: $(OBJECT) f15.6.o
	$(CC) $(CFLAGS) -o f15.6 $(OBJECT) f15.6.o

f15.6.o: f15.6.c
	$(CC) $(CFLAGS) -c f15.6.c

err.o: ../../error/err.c
	$(CC) $(CFLAGS) -c ../../error/err.c

clean:
	rm -f $(OBJECT) f15.5.o f15.6.o f15.5 f15.6
