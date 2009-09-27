CC = gcc
CFLAGS = -Wall -g
OBJECT = f4.12.o ../../error/err.o

f4.12: $(OBJECT)
	$(CC) $(CFLAGS) -o f4.12 $(OBJECT)

f4.12.o: f4.12.c
	$(CC) $(CFLAGS) -c f4.12.c

err.o: ../../error/err.c
	$(CC) $(CFLAGS) -c ../../error/err.c

clean:
	rm -f $(OBJECT) f4.12
