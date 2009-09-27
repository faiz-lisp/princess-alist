CC = gcc
CFLAGS = -Wall -g
OBJECT = f4.16.o ../../error/err.o

f4.16: $(OBJECT)
	$(CC) $(CFLAGS) -o f4.16 $(OBJECT)

f4.16.o: f4.16.c
	$(CC) $(CFLAGS) -c f4.16.c

err.o: ../../error/err.c
	$(CC) $(CFLAGS) -c ../../error/err.c

clean:
	rm -f $(OBJECT) f4.16
