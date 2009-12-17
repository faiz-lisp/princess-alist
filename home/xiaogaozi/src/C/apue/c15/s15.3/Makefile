CC = gcc
CFLAGS = -Wall -g
OBJECT = ../../error/err.o

all: f15.11 myuclc f15.15

f15.11: $(OBJECT) f15.11.o
	$(CC) $(CFLAGS) -o f15.11 $(OBJECT) f15.11.o

f15.11.o: f15.11.c
	$(CC) $(CFLAGS) -c f15.11.c

myuclc: $(OBJECT) f15.14.o
	$(CC) $(CFLAGS) -o myuclc $(OBJECT) f15.14.o

f15.14.o: f15.14.c
	$(CC) $(CFLAGS) -c f15.14.c

f15.15: $(OBJECT) f15.15.o
	$(CC) $(CFLAGS) -o f15.15 $(OBJECT) f15.15.o

f15.15.o: f15.15.c
	$(CC) $(CFLAGS) -c f15.15.c

err.o: ../../error/err.c
	$(CC) $(CFLAGS) -c ../../error/err.c

clean:
	rm -f $(OBJECT) f15.11.o f15.14.o f15.15.o f15.11 myuclc f15.15
