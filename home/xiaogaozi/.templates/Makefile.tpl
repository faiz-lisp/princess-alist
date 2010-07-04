CC = gcc
CFLAGS = -Wall -g
# CPPFLAGS = -I
# LDFLAGS = -L
EXEC = alist

alist: alist.o
	$(CC) $(CFLAGS) -o $@ $^

alist.o: alist.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f *.o $(EXEC)
